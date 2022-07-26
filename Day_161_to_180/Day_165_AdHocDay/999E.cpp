#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(...) 1;
#define print(...) 1;
#endif

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, s;
    std::cin >> n >> m >> s;

    s--;
    std::vector<int> adj[n], indeg(n);

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        adj[--u].push_back(--v);
        indeg[v]++;
    }

    std::vector<int> good(n);
    std::function<void(int)> dfs;

    dfs = [&](int u)
    {
        good[u] = 1;

        for (int v : adj[u])
        {
            if (not good[v])
                dfs(v);
        }
    };

    dfs(s);
    std::vector<int> cnt(n);
    std::vector<int> vis2 = good;
    std::function<void(int, int&)> dfs2 = [&](int u, int& count)
    {
        count++;
        vis2[u] = 1;

        for (int v : adj[u])
            if (!vis2[v])
                dfs2(v, count);
    };

    for (int i = 0; i < n; i++)
    {
        if (!good[i])
        {
            vis2 = good;
            dfs2(i, cnt[i]);
        }
    }

    std::vector<int> rem;
    for (int i = 0; i < n; ++i)
        if (!good[i])
            rem.push_back(i);

    std::sort(std::begin(rem), std::end(rem), [&cnt](int a, int b)
    {
        return cnt[a] > cnt[b];
    });
    int ans = 0;
    for (int ele : rem)
    {
        if (!good[ele])
            ans++, dfs(ele);
    }

    std::cout << ans << "\n";

    return 0;
}