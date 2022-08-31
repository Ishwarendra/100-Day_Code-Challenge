#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    i64 a, b, c, d;
    std::cin >> a >> b >> c >> d;  

    if (a * d == b * c)
        std::cout << "0\n";
    else
    {
        // dangling reference!
        // auto [min, max] = std::minmax(a * d, b * c);
        // std::cout << min << " " << max << " ";

        auto min = std::min(a * d, b * c);
        auto max = std::max(a * d, b * c);
        if (min != 0 and max % min)
            std::cout << "2\n";
        else
            std::cout << "1\n";
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