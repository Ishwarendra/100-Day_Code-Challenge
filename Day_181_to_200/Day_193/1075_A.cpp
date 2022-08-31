#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    auto primeFactor = [&](int x)
    {
        std::map<int, int> m;
        while (x % 2 == 0)
            m[2]++, x /= 2;
        while (x % 3 == 0)
            m[3]++, x /= 3;

        for (int i = 7; i * i <= x; i += 6)
        {
            while (x % i == 0)
                m[i]++, x /= i;
        }

        if (x > 1)
            m[x]++;

        return m;
    };

    std::map<int, std::vector<int>> m;
    int g = 0;
    for (int i = 0; i < n; ++i)
    {
        int x;
        std::cin >> x;

        auto pf = primeFactor(x);
        
        for (auto [num, f] : pf)
        {
            while (std::size(m[num]) <= f)
                m[num].emplace_back(0);
            
            m[num][f]++;
        }

        g = std::gcd(g, x);
    }

    int ans = n;

    for (auto &[num, p] : m)
    {
        int nonZero = 0;
        for (int i : p)
            nonZero += i > 0;

        for (int i = 0; i < std::size(p); i++)
        {
            if (p[i] and nonZero > 1)
            {
                ans = std::min(ans, p[i]);
                break;
            }
        }
    }

    if (ans == n)
        std::cout << "-1\n";
    else
        std::cout << ans << "\n";
    
    return 0;
}