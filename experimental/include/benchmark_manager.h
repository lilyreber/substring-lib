#ifndef BENCHMARK_MANAGER_H
#define BENCHMARK_MANAGER_H

#include <chrono>
#include <functional>
#include <iostream>
#ifdef _WIN32
#include <psapi.h>
#include <windows.h>
#elif __APPLE__
#include <mach/mach.h>
#include <sys/resource.h>
#else
#include <sys/resource.h>
#include <unistd.h>
#endif

class BenchmarkManager {
private:
    static std::size_t GetMemoryUsage() {
#ifdef _WIN32
        PROCESS_MEMORY_COUNTERS memInfo;
        GetProcessMemoryInfo(GetCurrentProcess(), &memInfo, sizeof(memInfo));
        return memInfo.WorkingSetSize / 1024.0;
#elif __APPLE__
        struct mach_task_basic_info info;
        mach_msg_type_number_t size = MACH_TASK_BASIC_INFO_COUNT;
        if (task_info(
                mach_task_self(), MACH_TASK_BASIC_INFO, (task_info_t)&info,
                &size
        ) == KERN_SUCCESS) {
            return info.resident_size / 1024.0;
        }
        return 0;
#else
        struct rusage usage;
        getrusage(RUSAGE_SELF, &usage);
        return usage.ru_maxrss;
#endif
    }

    template <typename F, typename... Args>
    static double MeasureFirstTime(F func, Args &&...args) {
        auto start = std::chrono::high_resolution_clock::now();
        func(std::forward<Args>(args)...);
        auto end = std::chrono::high_resolution_clock::now();

        return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    }

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
    template <typename F, typename... Args>
    static void
    Measure(const std::string &experiment_name, F func, Args &&...args) {
        std::size_t memory_before = GetMemoryUsage();
        auto time = MeasureFirstTime(func, std::forward<Args>(args)...);
        std::size_t memory_after = GetMemoryUsage();
        int times = 100;
        std::size_t avg_memory_before = GetMemoryUsage();
        auto avg_time = MeasureAvgTime(func, times, std::forward<Args>(args)...);
        std::size_t avg_memory_after = GetMemoryUsage();
        std::cerr << experiment_name << "\n\t"
            << time << " microseconds (single)\n\t"
            << memory_after - memory_before << " KB (single)\n\t"
            << avg_time << " microseconds (times=" << times << ")\n\t"
            << avg_memory_after - avg_memory_before << " KB (times=" << times << ")\n";
    }
};

#endif //BENCHMARK_MANAGER_H
