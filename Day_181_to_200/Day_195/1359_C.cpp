#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;
using l64 = long double;

void solve()
{
    int h, c, t;
    std::cin >> h >> c >> t;

    auto f = [&](int k) -> l64
    {
        return (1.0L * k * h + (k - 1.0L) * c) / (2.0L * k - 1);
    };   

    if (t * 2 <= (c + h))
        std::cout << "2\n";
    else
    {
        assert(2 * t - c - h > 0 and t - c > 0);
        i64 k1 = (t - c) / (2 * t - c - h);
        i64 k2 = (t - c + 2 * t - c - h - 1) / (2 * t - c - h);

        k1 = std::max(1LL, k1);
        k2 = std::max(1LL, k2);
        if (std::abs(f(k1) - t) <= std::abs(f(k2) - t))
            std::cout << 2 * k1 - 1 << std::endl;
        else
            std::cout << 2 * k2 - 1 << std::endl;
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