#include <iostream>
#include "utils/benchmark.h"

template <typename T>
void add(T *a, T *b, T *c, int n) {
    for (int i = 0; i < n; i++) {
        c[i] = a[i] + b[i];
    }
}

int main()
{

#ifdef __ARM_NEON
    std::cout << "ARM NEON enabled" << std::endl;
#else
    std::cout << "ARM NEON NOT enabled" << std::endl;
#endif   
    
    const size_t N = 1 << 20;
    double best_time;

    // =============================================
    uint8_t *A_u8 = new uint8_t[N];
    uint8_t *B_u8 = new uint8_t[N];
    uint8_t *C_u8 = new uint8_t[N];

    for(int i = 0; i < N; i++)
    {
        A_u8[i] = rand() & 0xFF;
        B_u8[i] = rand() & 0xFF;
    }

    best_time = benchmark(10, [&]() {
        add<uint8_t>(A_u8, B_u8, C_u8, N);
    });
    std::cout << "uint8 best_time: " << best_time * 1000 << " ms" << std::endl;

    delete [] A_u8;
    delete [] B_u8;
    delete [] C_u8;

    // =============================================
    uint16_t *A_u16 = new uint16_t[N];
    uint16_t *B_u16 = new uint16_t[N];
    uint16_t *C_u16 = new uint16_t[N];

    best_time = benchmark(10, [&]() {
        add<uint16_t>(A_u16, B_u16, C_u16, N);
    });
    std::cout << "uint16 best_time: " << best_time * 1000 << " ms" << std::endl;

    delete [] A_u16;
    delete [] B_u16;
    delete [] C_u16;

    // =============================================
    uint32_t *A_u32 = new uint32_t[N];
    uint32_t *B_u32 = new uint32_t[N];
    uint32_t *C_u32 = new uint32_t[N];

    best_time = benchmark(10, [&]() {
        add<uint32_t>(A_u32, B_u32, C_u32, N);
    });
    std::cout << "uint32 best_time: " << best_time * 1000 << " ms" << std::endl;

    delete [] A_u32;
    delete [] B_u32;
    delete [] C_u32;

    // =============================================
    __fp16 *A_f16 = new __fp16[N];
    __fp16 *B_f16 = new __fp16[N];
    __fp16 *C_f16 = new __fp16[N];

    best_time = benchmark(10, [&]() {
        add<__fp16>(A_f16, B_f16, C_f16, N);
    });
    std::cout << "fp16 best_time: " << best_time * 1000 << " ms" << std::endl;

    delete [] A_f16;
    delete [] B_f16;
    delete [] C_f16;

    // =============================================
    float *A_f32 = new float[N];
    float *B_f32 = new float[N];
    float *C_f32 = new float[N];

    best_time = benchmark(10, [&]() {
        add<float>(A_f32, B_f32, C_f32, N);
    });
    std::cout << "fp32 best_time: " << best_time * 1000 << " ms" << std::endl;

    delete [] A_f32;
    delete [] B_f32;
    delete [] C_f32;
   
    return 0;
}