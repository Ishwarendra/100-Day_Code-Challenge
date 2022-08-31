#include <bits/stdc++.h>
#include <iostream>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int x;
    std::cin >> x;

    std::vector<int> key(4);
    for (int i = 1; i < 4; ++i)  
        std::cin >> key[i];

    std::vector<int> vis(4);
    vis[x] = 1;
    vis[key[x]] = 1;
    vis[key[key[x]]] = 1;
    vis[key[key[key[x]]]] = 1;

    for (int i = 1; i < 4; i++)
    {
        if (!vis[i])
        {
            std::cout << "NO\n";
            return;
        }
    }

    std::cout << "YES\n";
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