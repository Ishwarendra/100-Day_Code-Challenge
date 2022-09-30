#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

bool isPrime(int n)
{
    if (n < 2)
        return false; 
    for (int x : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
    {
        if (n == x)
            return true;
        bool flag = true;
        int r = 1;
        int t = 1;
        while (r <= ((n - 1) >> __builtin_ctz(n - 1)))
        {
            if (r & ((n - 1) >> __builtin_ctz(n - 1)))
                t = (1LL * t * x) % n;
            x = (1LL * x * x) % n;
            r <<= 1;
        }
        if (t == 1 || t == n - 1)
            flag = false;
        for (r = 0; r < __builtin_ctz(n - 1); r++)
        {
            t = (1LL * t * t) % n;
            if (t == n - 1)
                flag = false;
        }
        if (flag)
            return false;
    }
    return true;
}

void solve()
{
    int x, d;
    std::cin >> x >> d;

    if (1LL * x % (1LL * d * d))
    {
        std::cout << "NO\n";
        return;
    }

    int cnt = 0;
    while (x % d == 0)
        x /= d, cnt++;

    bool x_prime = isPrime(x);
    bool d_prime = isPrime(d);

    if (d_prime or cnt == 2)
    {
        if (x_prime or x == 1)
            std::cout << "NO\n";
        else
            std::cout << "YES\n";
    }
    else if (1LL * x * x == d and cnt == 3 and x_prime)
        std::cout << "NO\n";
    else
        std::cout << "YES\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--)
        solve();

    return 0;
}