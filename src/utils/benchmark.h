#ifndef A841EA13_1E65_4B49_B244_F169525118AA
#define A841EA13_1E65_4B49_B244_F169525118AA

// adapted from "halide_benchmark.h"

#include <cstdint>
#include <chrono>
#include <functional>
#include <limits>
#include <iostream>

// Prefer high_resolution_clock, but only if it's steady...
template<bool HighResIsSteady = std::chrono::high_resolution_clock::is_steady>
struct SteadyClock {
    using type = std::chrono::high_resolution_clock;
};

// ...otherwise use steady_clock.
template<>
struct SteadyClock<false> {
    using type = std::chrono::steady_clock;
};

inline SteadyClock<>::type::time_point benchmark_now() {
    return SteadyClock<>::type::now();
}

inline double benchmark_duration_seconds(
    SteadyClock<>::type::time_point start,
    SteadyClock<>::type::time_point end) {
    return std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count();
}

inline double benchmark(uint64_t iterations, const std::function<void()> &op) {
    double best = std::numeric_limits<double>::infinity();
    for (uint64_t i = 0; i < iterations; i++) {
        auto start = benchmark_now();
        op();
        auto end = benchmark_now();
        double elapsed_seconds = benchmark_duration_seconds(start, end);
        best = std::min(best, elapsed_seconds);    
        // std::cout << "elapsed_seconds: " << elapsed_seconds * 1000 << "ms" << std::endl;
    }
    return best;
}

#endif /* A841EA13_1E65_4B49_B244_F169525118AA */
