#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr i64 inf = 1e18;

// charmi kami
void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> adj[n];
    for (int i = 1; i < n; i++)  
    {
        int p;
        std::cin >> p;
        --p;
        adj[p].emplace_back(i);
    }

    std::vector<int> s(n);
    for (int i = 0; i < n; i++)
        std::cin >> s[i];

    std::vector<std::map<int, i64>> dp(n);
    std::function<i64(int, int)> dfs = [&](int u, int c) -> i64 // sum(c_i * s_i)
    {
        // node u is chosen c times
        int children = std::size(adj[u]);
        if (dp[u].contains(c))
            return dp[u][c];

        if (children == 0)
            return dp[u][c] = 1LL * c * s[u];

        int q = c / children; // all get 
        int rem = c % children; // some get

        dp[u][c] = 1LL * s[u] * c;
        std::multiset<i64> options;
        for (auto v : adj[u])
        {
            if (rem)
                options.emplace(dfs(v, q + 1) - dfs(v, q));
            dp[u][c] += dfs(v, q + !!rem);
        }

        rem = children - rem;

        while (rem-- > 0 and !options.empty())
        {
            dp[u][c] -= *std::begin(options);
            options.erase(std::begin(options));
        }

        return dp[u][c];
    }; dfs(0, k);

    std::cout << dp[0][k] << "\n";
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