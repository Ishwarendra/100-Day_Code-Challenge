#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        std::cin >> x >> y;

        ans = std::max(ans, x + y);
    }

    std::cout << ans << "\n";
    
    return 0;
}