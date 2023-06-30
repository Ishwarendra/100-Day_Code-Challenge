#include "bits/stdc++.h"

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
    std::cin >> n;

    std::vector dp(1 << n, std::vector(n + 1, 0));
    for (int i = 0; i < (1 << n); i++)
        std::cin >> dp[i][0];

    auto getBit = [&](int x, int pos) { return x >> pos & 1; };

    for (int mask = 0; mask < (1 << n); mask++)
    {
        for (int i = 0; i < n; i++)
        {
            if (!getBit(mask, i))
                dp[mask][i + 1] = dp[mask][i];
            else
                dp[mask][i + 1] = dp[mask][i] + dp[mask ^ (1 << i)][i];
        }
    }

    std::vector<int> ans(1 << n);
    for (int mask = 0; mask < (1 << n); mask++)
    {
        int sum = 0;
        for (int i = mask; i > 0; i = (i - 1) & mask)
            sum += dp[i][0];
        std::cout << sum + dp[0][0] << " \n"[mask == (1 << n) - 1];
    }

    for (int i = 0; i < (1 << n); i++)
        std::cout << dp[i][n] << " \n"[i == (1 << n) - 1];

    return 0;
}