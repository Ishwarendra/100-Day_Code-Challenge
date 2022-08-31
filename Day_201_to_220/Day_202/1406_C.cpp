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

    std::vector<int> adj[n];
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        adj[--u].emplace_back(--v);
        adj[v].emplace_back(u);
    }

    for (int i = 0; i < n; i++)
        std::sort(std::begin(adj[i]), std::end(adj[i]));

    std::vector<int> dp(n), par(n, -1);
    std::function<int(int)> dfs;
    dfs = [&](int u)
    {
        dp[u] = 1;
        for (int v : adj[u])
        {
            if (v != par[u])
            {
                par[v] = u;
                dp[u] += dfs(v);
            }
        }

        return dp[u];
    };

    dfs(0);
    int size = n + 1;
    std::vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        int cur_size = n - dp[i];
        for (auto v : adj[i])
        {
            if (v != par[i])
                cur_size = std::max(cur_size, dp[v]);
        }

        if (cur_size < size)
        {
            size = cur_size;
            ans = std::vector<int>(1, i);
        }
        else if (cur_size == size)
            ans.emplace_back(i);
    }

    if (std::size(ans) == 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (!adj[i].empty())
            {
                std::cout << i + 1 << " " << adj[i][0] + 1 << "\n";
                std::cout << i + 1 << " " << adj[i][0] + 1 << "\n";
                return;
            }
        }
    }
    else
    {
        assert(std::size(ans) == 2);
        assert(std::binary_search(std::begin(adj[ans[0]]), std::end(adj[ans[0]]), ans[1]));

        int x = ans[0], y = ans[1];

        if (std::size(adj[x]) < std::size(adj[y]))
            std::swap(x, y);

        int rem = -1;
        for (int u : adj[x])
        {
            if (u != y)
            {
                rem = u;
                std::cout << u + 1 << " " << x + 1 << "\n";
                break;
            }
        }

        assert(rem != -1);
        std::cout << rem + 1 << " " << y + 1 << "\n";
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