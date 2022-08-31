#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

constexpr i64 inf = 1e16;

void solve()
{
    int n, a, b;
    std::cin >> n >> a >> b;

    std::string s;
    std::cin >> s;

    std::vector<std::vector<i64>> dp(n + 1, std::vector<i64>(2, inf));
    dp[0][0] = b;
    // dp[0][1] = inf;

    for (int i = 1; i <= n; ++i)
    {
        if (s[i - 1] == '1')
            dp[i][1] = std::min(dp[i][1], dp[i - 1][1] + 2LL * b + a);
        else
        {
            dp[i][0] = std::min(dp[i - 1][0] + a + b, dp[i - 1][1] + 2LL * a + b);
            dp[i][1] = std::min(dp[i - 1][1] + 2LL * b + a, dp[i - 1][0] + 2LL * b + 2LL * a);
        }
    }

    std::cout << dp[n][0] << std::endl;
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