#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;
using l64 = long double;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;

    int left = 0, right = n - 1;
    int ans = -1;

    auto f = [&](int y) -> i64
    {
        return 1LL * y * y + 1LL * y * (-2LL * n - 3LL) + (1LL * n * n + n - 2LL * k);
    };

    while (left <= right) 
    {
        int y = (left + right) / 2;
        i64 lhs = f(y);

        if (lhs == 0)
        {
            std::cout << y << "\n";
            return 0;
        }
        if (lhs > 0)
             left = y + 1;
        else 
            right = y - 1;
    }

    // assert(false);

    return 0;
}