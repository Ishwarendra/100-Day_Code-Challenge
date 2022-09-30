#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;
        
    std::map<int, int> m;
    for (int i = 0; i < n; ++i)
    {
        int x;
        std::cin >> x;
        m[x]++;
    }

    std::multiset<int> extra;
    for (auto [num, f] : m)
    {
        if (f > 1)
            extra.emplace(num);
    }

    std::vector<i64> ans(n + 1, -1);
    ans[0] = (m.contains(0) ? m[0] : 0);

    if (!m.contains(0))
    {
        std::cout << "0 ";
        for (int i = 1; i <= n; i++)
            std::cout << -1 << " \n"[i == n];

        return;
    }

    i64 prev = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (m.contains(i))
            ans[i] = prev + m[i];
        else
        {
            ans[i] = prev;
            auto it = extra.lower_bound(i);
            if (it == std::begin(extra))
                break;
            it--;

            prev += i - (*it);

            m[i]++;
            m[*it]--;

            if (m[i] > 1)
                extra.emplace(i);
            if (m[*it] < 2)
                extra.erase(extra.find(*it));
        }   
    }

    for (int i = 0; i < n + 1; ++i)
        std::cout << ans[i] << " \n"[i == n]; 
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