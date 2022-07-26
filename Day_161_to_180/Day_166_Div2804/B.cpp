#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

void solve()
{
    std::vector<std::vector<int>> grid 
    {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0}
    };

    int n, m;
    std::cin >> n >> m;

    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < m; ++j)
            std::cout << grid[i % 4][j % 4] << " ";
        std::cout << "\n";
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