#ifndef BENCHMARK_MANAGER_H
#define BENCHMARK_MANAGER_H

#include <chrono>
#include <functional>
#include <iostream>
#include <string>
#ifdef _WIN32
#include <psapi.h>
#include <windows.h>
#elif __APPLE__
#include <mach/mach.h>
#include <sys/resource.h>
#include <unistd.h>
#else
#include <sys/resource.h>
#include <unistd.h>

#include <fstream>
#endif

// manager for different OS types and calculate metrics
class BenchmarkManager {
   private:
    // calculate used memory
    static std::size_t GetMemoryUsage() {
#ifdef _WIN32  // for Windows
        PROCESS_MEMORY_COUNTERS memInfo;
        GetProcessMemoryInfo(GetCurrentProcess(), &memInfo, sizeof(memInfo));
        return memInfo.WorkingSetSize / 1024.0;
#elif __APPLE__  // for macOs
        struct mach_task_basic_info info;
        mach_msg_type_number_t size = MACH_TASK_BASIC_INFO_COUNT;
        if (task_info(mach_task_self(), MACH_TASK_BASIC_INFO, (task_info_t)&info, &size) == KERN_SUCCESS) {
            return info.resident_size / 1024.0;
        }
        return 0;
#else            // for Linux
        struct rusage usage;
        getrusage(RUSAGE_SELF, &usage);
        return usage.ru_maxrss;

#endif
    }

    // calculate used time for single search
    template <typename F, typename... Args>
    static double MeasureFirstTime(F func, Args &&...args) {
        auto start = std::chrono::high_resolution_clock::now();
        func(std::forward<Args>(args)...);
        auto end = std::chrono::high_resolution_clock::now();

        return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    }

    // calculate average time for 'times' function executions
    template <typename F, typename... Args>
    static double MeasureAvgTime(F func, int times, Args &&...args) {
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < times; ++i) {
            func(std::forward<Args>(args)...);
        }
        auto end = std::chrono::high_resolution_clock::now();

        return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / times;
    }

   public:
    // common metrics, take experiment_name, functions and args for function
    template <typename F, typename... Args>
    static void Measure(const std::string &experiment_name, F func, Args &&...args) {
        std::size_t memory_before = GetMemoryUsage();  // single execution
        auto time = MeasureFirstTime(func, std::forward<Args>(args)...);
        std::size_t memory_after = GetMemoryUsage();
        int times = 100;  // choose your own number for average time and memory usage
        std::size_t avg_memory_before = GetMemoryUsage();
        auto avg_time = MeasureAvgTime(func, times, std::forward<Args>(args)...);
        std::size_t avg_memory_after = GetMemoryUsage();
        // print result
        std::cerr << experiment_name << "\n\t" << time << " microseconds (single)\n\t" << memory_after - memory_before
                  << " KB (single)\n\t" << avg_time << " microseconds (times=" << times << ")\n\t"
                  << ((avg_memory_after - avg_memory_before) / times) << " KB (times=" << times << ")\n";
    }
};

#endif  // BENCHMARK_MANAGER_H
