#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int a, b, x, mod, k;
    std::cin >> a >> b >> mod >> x >> k;

    std::set<i64> dp;
    i64 prev = std::abs(1LL * a * x + b) % mod;

    dp.emplace(prev);
    std::vector<i64> cycle(1, prev);

    while (true)
    {
        i64 cur = std::abs(1LL * a * prev + b) % mod;
        cycle.emplace_back(cur);

        if (dp.count(cur))
            break;

        dp.emplace(cur);
        prev = cur;
    }
    int sz = 1, st = 0;
    for (int i = 0; i < std::size(cycle); i++)
    {
        if (cycle[i] == cycle.back())
        {
            sz = (int)std::size(cycle) - i - 1, st = i;
            break;
        }
    }
    print(cycle, sz, st)

    if (--k < st)
        std::cout << cycle[k] << "\n";
    else
    {
        k -= st;
        k %= sz;
        std::cout << cycle[st + k] << "\n";
    }
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