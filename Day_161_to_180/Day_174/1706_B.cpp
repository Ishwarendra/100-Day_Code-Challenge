#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

void solve()
{
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n; ++i)  
    {
        int x;
        std::cin >> x;

        adj[--x].emplace_back(i);
    }

    auto get = [&](int col)
    {
        int sz = !adj[col].empty();

        for (int i = 1; i < std::size(adj[col]); i++)
            sz += (adj[col][i] - adj[col][i - 1] - 1) % 2 == 0;

        return sz;
    };

    for (int i = 0; i < n; ++i)
        std::cout << get(i) << " \n"[i == n - 1];
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