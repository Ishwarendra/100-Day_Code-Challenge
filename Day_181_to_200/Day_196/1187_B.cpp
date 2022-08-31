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
    std::string s;
    std::cin >> n >> s;

    std::vector<std::vector<int>> adj(26);

    for (int i = 0; i < n; i++)
        adj[s[i] - 'a'].emplace_back(i);

    int m;
    std::cin >> m;

    for (int i = 0; i < m; ++i)
    {
        std::string a;
        std::cin >> a;

        std::map<int, int> m;
        for (char ch : a)
            m[ch - 'a']++;

        int max = 0;
        for (auto [x, f] : m)
        {
            assert(f - 1 < std::size(adj[x]) and f - 1 >= 0);
            max = std::max(max, adj[x][f - 1]);
        }

        std::cout << max + 1 << "\n";
    }
    
    return 0;
}