#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;

    const int mod = k;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    auto primeFactor = [](int x)
    {
        std::map<int, int> m;
        for (int i = 2; i * i <= x; i++)
        {
            while (x % i == 0)
                x /= i, m[i]++;
        }

        if (x > 1)
            m[x]++;

        return m;
    };

    std::vector<std::vector<std::pair<int, int>>> b(n);
    for (int i = 0; i < n; ++i)
    {
        auto pf = primeFactor(a[i]);
        for (auto [p, e] : pf)
        {
            if (e % k)
                b[i].emplace_back(p, e % k);
        }
    }

    auto need_f = [&k](const std::vector<std::pair<int, int>> &a)
    {
        std::vector<std::pair<int, int>> x;
        for (auto [p, e] : a)
            x.emplace_back(p, k - e);

        return x;
    };

    std::map<std::vector<std::pair<int, int>>, int> mp;

    i64 ans = 0;
    for (int i = 0; i < n; i++)
    {
        auto need = need_f(b[i]);
        ans += mp[need];
        mp[b[i]]++;
    }

    std::cout << ans;
    
    return 0;
}