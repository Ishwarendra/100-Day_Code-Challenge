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

    i64 h;
    int n;
    std::cin >> h >> n;

    std::vector<int> d(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> d[i];
        d[i] *= -1;
    }

    std::vector<i64> dp(n);

    dp[0] = d[0];
    for (int i = 1; i < n; i++)
        dp[i] += dp[i - 1] + d[i];

    i64 sum = dp[n - 1];

    for (int i = 0; i < n; ++i)
    {
        if (dp[i] >= h)
        {
            std::cout << i + 1 << "\n";
            return 0;
        }
    }

    if (sum <= 0)
        std::cout << "-1\n";
    else
    {
        int max_id = std::max_element(std::begin(dp), std::end(dp)) - std::begin(dp);
        i64 k = (h - dp[max_id] + sum - 1) / sum;

        h -= k * sum;
        int id = 0;
        for (int i = 0; i < n; ++i)
        {
            if (dp[i] >= h)
            {
                id = i;
                break;
            }
        }
        
        std::cout << k * n + id + 1 << "\n";
    }

    return 0;
}