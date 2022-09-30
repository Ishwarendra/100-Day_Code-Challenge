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

    int n;
    i64 m;
    std::cin >> n >> m; 

    auto less = [&](i64 m)
    {
        int left = 0, right = n;
        int ans = 0;

        while (left <= right)
        {
            int mid = (left + right) >> 1;

            if (1LL * mid * (mid - 1) / 2 >= m)
                ans = mid, right = mid - 1;
            else
                left = mid + 1;
        }
        
        return ans;
    };
    
    i64 max = n - less(m);
    i64 min;
    if (m >= (n + 1) / 2)
        min = 0;
    else
        min = n - 2 * m;

    std::cout << min << " " << max << "\n";

    return 0;
}