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
    
    int n;
    std::cin >> n;

    std::multiset<int> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;

        m.emplace(x);
    }

    int f, x;
    std::cin >> x >> f;

    i64 ans = 0;

    while (!m.empty())
    {
        int cur = *std::begin(m);
        if (cur <= x)
        {
            m.erase(std::begin(m));
            continue;
        }

        ans += (cur - x + x + f - 1) / (x + f);
        m.erase(std::begin(m));
    }

    std::cout << ans * f;
    
    return 0;
}