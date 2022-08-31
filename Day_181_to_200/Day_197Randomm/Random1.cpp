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

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    int team, m;
    std::cin >> team >> m;

    std::multiset<std::pair<int, int>, std::greater<>> pq;

    int fend = 0, lend = n - 1;
    std::vector<int> vis(n);
    while (fend < n and fend < m)
    {
        vis[fend] = 1;
        pq.emplace(a[fend], -1LL * fend);
        fend++;
    }

    while (!vis[lend] and n - lend <= m)
    {
        vis[lend] = 1;
        pq.emplace(a[lend], -1LL * lend);
        lend--;
    }

    i64 ans = 0;
    while (!pq.empty() and team--)
    {
        ans += std::begin(pq)->first;

        auto id = std::begin(pq)->second;
        id = std::abs(id);

        pq.erase(std::begin(pq));
        if (id + 1 < n and id + 1 == fend and !vis[id + 1])
        {
            vis[fend++] = 1;
            pq.emplace(a[id + 1], id + 1);
        }

        if (id - 1 >= 0 and id - 1 <= lend and !vis[id - 1])
        {
            vis[lend--] = 1;
            pq.emplace(a[id - 1], id - 1);
        }
    }

    std::cout << ans;
    
    return 0;
}