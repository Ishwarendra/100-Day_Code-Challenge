#include <bits/stdc++.h>

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
    
    int n = 2;
    std::cout << n << "\n";
    for (int i = 0; i < n; ++i)
    {
        int len = get_rand<int>(1, 3);
        std::cout << len << " ";
        for (int j = 0; j < len; ++j)
            std::cout << get_rand<int>(0, 20) << " ";
        std::cout << "\n";
    }
    
    return 0;
}