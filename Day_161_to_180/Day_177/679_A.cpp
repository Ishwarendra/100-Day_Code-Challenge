#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

std::vector<int> primes;
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
                t = ((int)t * x) % n;

            x = ((long long)x * x) % n;
            r <<= 1;
        }
        if (t == 1 || t == n - 1)
            flag = false;
        for (r = 0; r < __builtin_ctz(n - 1); r++)
        {
            t = ((int)t * t) % n;
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
    auto ask = [&](int x)
    {
        std::cout << x << std::endl;
        std::string s;
        std::cin >> s;

        return s;
    };

    int cnt = 0;

    for (int p : primes)
    {
        auto s = ask(p);
        cnt +=  s == "yes";
    }

    for (int p : {4, 9, 25, 49})
    {
        auto s = ask(p);
        cnt += s == "yes";
    }

    if (cnt >= 2)
        std::cout << "composite" << std::endl;
    else
        std::cout << "prime" << std::endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (int i = 2; i <= 50; i++)
    {
        if (isPrime(i))
            primes.emplace_back(i);
    }

    int t = 1;
    
    while (t--)
        solve();
    
    return 0;
}