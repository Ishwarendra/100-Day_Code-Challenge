#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> adj[n];
    for (int i = 1; i < n; i++)  
    {
        int p;
        std::cin >> p;

        adj[--p].emplace_back(i);
    }

    std::vector<int> l(n), r(n);
    for (int i = 0; i < n; ++i)
        std::cin >> l[i] >> r[i];

    std::function<i64(int)> dfs;
    int ans = 0;
    dfs = [&](int u) -> i64
    {
        i64 max = 0;
        for (int v : adj[u])
            max += dfs(v);

        if (max < 1LL * l[u])
        {
            ans++;
            return r[u] * 1LL;
        }

        return std::min(r[u] * 1LL, max);
    };

    dfs(0);
    std::cout << ans << "\n";
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