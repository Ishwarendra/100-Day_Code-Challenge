#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

void solve()
{
    int x, y;
    std::cin >> x >> y;

    if (x == 1)
        std::cout << (y == 1 ? "YES\n" : "NO\n");
    else if (x == 2 or x == 3)
        std::cout << (y <= 3 ? "YES\n" : "NO\n");
    else
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