#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
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

    auto square = [&](int x)
    {
        return 1LL * x * x;
    };

    for (int i = 0; i < n; ++i)
    {
        int c, sum;
        std::cin >> c >> sum;

        if (sum <= c)
        {
            std::cout << sum << "\n";
            continue;
        }

        int x = sum % c;
        std::cout << x * square(sum / c + 1) + (c - x) * square(sum / c) << "\n";
    } 
    
    return 0;
}