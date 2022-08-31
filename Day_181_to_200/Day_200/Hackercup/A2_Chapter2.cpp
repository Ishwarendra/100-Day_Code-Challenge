#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

void solve()
{
    std::string s;
    int k;
    std::cin >> s >> k;

    std::vector<int> adj[26];
    for (int i = 0; i < k; ++i)
    {
        char ch1, ch2;
        std::cin >> ch1 >> ch2;

        adj[ch1 - 'A'].emplace_back(ch2 - 'A');
    }

    constexpr int inf = 1e9;
    auto path_len = [&](int from, int to)
    {
        std::vector<int> d(26, inf);
        d[from] = 0;

        std::set<std::pair<int, int>> s;
        s.emplace(d[from], from);

        while (!s.empty())
        {
            auto [_, u] = *std::begin(s);
            s.erase(std::begin(s));

            for (int v : adj[u])
            {
                if (d[v] > d[u] + 1)
                {
                    s.erase({d[v], v});
                    d[v] = d[u] + 1;
                    s.emplace(d[v], v);
                }
            }
        }

        return d[to];
    };

    auto f = [&](char ch)
    {
        int n = std::size(s);
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (ch == s[i])
                continue;

            int dist = path_len(s[i] - 'A', ch - 'A');
            if (dist == inf)
                return inf;

            ans += dist;
        }

        return ans;
    };

    int ans = inf;

    for (char ch = 'A'; ch <= 'Z'; ch++)
        ans = std::min(ans, f(ch));

    std::cout << (ans == inf ? -1 : ans) << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    for (int i = 1; i <= t; i++)
    {
        std::cout << "Case #" << i << ": ";
        solve();
    }
    
    return 0;
}   