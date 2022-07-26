#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using l64 = long double;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cout << std::fixed;
    std::cout << std::setprecision(8); 

    int n;
    std::cin >> n;

    std::vector<int> x(n), v(n);
    for (int i = 0; i < n; ++i)
        std::cin >> x[i] >> v[i];

    l64 eps = 1e-8;
    l64 left = 0, right = 2e9, ans = 0;

    auto good = [&](l64 limit)
    {
        std::pair<l64, l64> xrange = {-1e9, 1e9};
        for (int i = 0; i < n; ++i)
        {
            xrange.first = std::max(xrange.first, x[i] * 1.0L - limit * v[i]);
            xrange.second = std::min(xrange.second, x[i] * 1.0L + limit * v[i]);
        }

        return xrange.first <= xrange.second; 
    };

    while (right - left > eps)
    {
        l64 mid = (left + right) / 2.0;

        if (good(mid))
            ans = right = mid;
        else
            left = mid;
    }

    std::cout << ans << "\n";
    
    return 0;
}