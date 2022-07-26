#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

void solve()
{
    const int n = 9;
    std::vector<std::string> a(n);
    for (int i = 0; i < n; ++i)  
        std::cin >> a[i];

    std::vector<std::pair<int, int>> to_change {
        {0, 0}, {3, 1}, {6, 2}
    };

    for (int i = 0; i < 3; ++i)
    {
        for (auto [x, y] : to_change)
        {
            x += i * 1, y += i * 3;
            a[x][y] = (a[x][y] == '1' ? '2' : '1');
        }
    }

    for (int i = 0; i < n; ++i)
        std::cout << a[i] << "\n";
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