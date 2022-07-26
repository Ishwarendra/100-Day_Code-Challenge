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

    constexpr int inf = 1e9 + 1;
    int ans = 0;
    std::vector<i64> pass(n);

    std::vector<std::vector<int>> adj(n), range(n, std::vector<int>(2));
    for (int i = 1; i < n; i++)
    {
        int x;
        std::cin >> x;

        adj[--x].push_back(i);
    }

    for (int i = 0; i < n; ++i)
        std::cin >> range[i][0] >> range[i][1];

    std::function<void(int)> dfs;
    dfs = [&](int u)
    {
        i64 to_pass = 0;

        for (int v : adj[u])
        {
            dfs(v);
            to_pass += pass[v];
        }

        print(u + 1, to_pass)
        pass[u] = std::min(to_pass, 1LL * range[u][1]);
        if (range[u][0] > to_pass)
        {
            print(u + 1)
            ans++, pass[u] = range[u][1];
        }
    };
    dfs(0);
    print(pass)
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