#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

template<class T>
T power(T a, int b) 
{
    T res = 1;
    for (; b; b /= 2, a *= a) 
    {
        if (b % 2) 
            res *= a;
    }
    return res;
} 

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto isPrime = [&](int x)
    {
        for (int i = 2; i * i <= x; i++)
        {
            if (x % i == 0)
                return false;
        }

        return true;
    };

    int n;
    std::cin >> n;

    std::vector<int> p;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i))
            p.emplace_back(i);
    }

    int sz = 0;

    for (int i = 0; i < std::ssize(p); i++)
    {
        for (int j = i + 1; j < std::ssize(p); j++)
        {
            if (p[i] * p[j] > n)
                break;

            for (int x = 0; 1LL * power(p[i], x + 1) * p[j] <= n; x++)
            {
                for (int y = 0; 1LL * power(p[j], y + 1) * power(p[i], x + 1) <= n; y++)
                    sz++;
            }
        }
    }

    std::cout << sz;

    return 0;
}