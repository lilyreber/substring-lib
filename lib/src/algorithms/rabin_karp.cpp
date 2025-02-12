#include "rabin_karp.h"

// Constractor saves pattern
RabinKarp::RabinKarp(const std::string& pattern) : pattern(pattern) {}

// Hash-function
long long calculateHash(const std::string& str, int start, int end, long long prime, long long base) {
    long long hash = 0;
    for (int i = start; i < end; ++i) {
        hash = (hash * base + str[i]) % prime;
    }
    return hash;
}

// Function to find a substring using the Rabin-Karp algorithm
std::vector<std::size_t> RabinKarp::search(const std::string& text) const {
    std::vector<std::size_t> occurrences;
    int n = text.length();
    int m = pattern.length();
    if (n < m || m == 0) return occurrences;

    long long prime = 101;  // Prime number to hash
    long long base = 256;   // Hash Basis

    // Calculate the hash for the pattern and the first text window
    long long patternHash = calculateHash(pattern, 0, m, prime, base);
    long long textHash = calculateHash(text, 0, m, prime, base);

    // Calculate base^(m-1) for quick hash recalculation
    long long power = 1;
    for (int i = 0; i < m - 1; ++i) {
        power = (power * base) % prime;
    }

    for (int i = 0; i <= n - m; ++i) {
        // If the hashes match, check the characters
        if (patternHash == textHash) {
            bool match = true;
            for (int j = 0; j < m; ++j) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                occurrences.push_back(i);
            }
        }

        // Recalculate the hash for the next text window
        if (i < n - m) {
            textHash = (base * (textHash - text[i] * power) + text[i + m]) % prime;
            if (textHash < 0) {
                textHash += prime;
            }
        }
    }

    return occurrences;
}
