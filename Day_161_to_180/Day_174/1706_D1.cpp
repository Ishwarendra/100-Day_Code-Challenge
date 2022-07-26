#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)  
        std::cin >> a[i];

    std::vector<std::vector<int>> adj(n);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 1; j <= k; j++)
        {
            adj[i].push_back(a[i] / j);

            if (j > a[i])
                break;
        }

        std::sort(std::begin(adj[i]), std::end(adj[i]));
        int _ = std::unique(std::begin(adj[i]), std::end(adj[i])) - std::begin(adj[i]);
        adj[i].resize(_);
    }

    constexpr int inf = 1e9;
    auto get = [&]()
    {
        // num, which, where
        std::multiset<std::tuple<int, int, int>> m;

        for (int i = 0; i < n; i++)
            m.emplace(adj[i][0], i, 0);

        int ans = inf;
        while (!m.empty())
        {
            auto &[min, which, where] = *std::begin(m);
            auto &[max, _, __] = *(--std::end(m));

            ans = std::min(ans, max - min);

            m.erase(m.begin());

            if (where + 1 >= std::size(adj[which]))
                break;

            m.emplace(adj[which][where + 1], which, where + 1);
        }

        return ans;
    };

    std::cout << get() << "\n";
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