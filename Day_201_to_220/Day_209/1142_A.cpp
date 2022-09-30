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
    
    int n, k, a, b;
    std::cin >> n >> k >> a >> b;

    if (a < b)
        std::swap(a, b);

    i64 max = 0, min = 1e18;
    i64 end = 1LL * n * k;

    for (int i = 0; i < n; ++i)
    {
        i64 one = 1LL * i * k + a + b;
        i64 two = 1LL * i * k + a - b;
        
        max = std::max(max, end / std::gcd(one, end));
        max = std::max(max, end / std::gcd(two, end));

        min = std::min(min, end / std::gcd(one, end));
        min = std::min(min, end / std::gcd(two, end));
    }

    std::cout << min << " " << max;
    
    return 0;
}