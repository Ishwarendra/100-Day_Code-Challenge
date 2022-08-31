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
    
    int a, b, c, d, e, f;
    std::cin >> a >> b >> c >> d >> e >> f;

    i64 ans = 0;
    for (int type1 = 0; type1 <= std::min(a, d); type1++)
    {
        int type2 = std::min({b, c, d - type1});
        ans = std::max(ans, 1LL * type1 * e + 1LL * type2 * f); 
    }

    std::cout << ans;
    
    return 0;
}