#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

std::seed_seq seed
{
    (uint32_t)std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count(),
    (uint32_t)std::random_device()(),
    (uint32_t)(uintptr_t)std::make_unique<char>().get(),
    (uint32_t)__builtin_ia32_rdtsc()
};
std::mt19937 rng(seed);

template<class T = int> 
T get_rand(T l, T r) 
{
    assert(l <= r);
    return std::uniform_int_distribution<T>(l, r)(rng);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n = get_rand(2, 3), c = get_rand(0, 10), d = get_rand(0, 10);
    std::cout << n << " " << c << " " << d << "\n";

    for (int i = 0; i < n; ++i)
    {
        int b = get_rand(1, 8), p = get_rand(1, 8);
        int ch = get_rand(0, 1);

        std::cout << b << " " << p << " ";
        if (ch == 0)
            std::cout << 'C' << "\n";
        else
            std::cout << 'D' << "\n";
    }
    
    return 0;
}