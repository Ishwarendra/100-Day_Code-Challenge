#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

using i64 = long long;

// Recursion TLE :dk:

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, x;
    std::cin >> n >> x;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    i64 dp[n][2][2];
    memset(dp, 0, sizeof dp);

    dp[0][0][0] = 0;
    dp[0][0][1] = 0; // no sense but let's keep it this way
    dp[0][1][0] = std::max(0LL, a[0] * 1LL);
    dp[0][1][1] = std::max(0LL, 1LL * x * a[0]);

    i64 ans = std::max({0LL, dp[0][1][0], dp[0][1][1]});

    for (int i = 1; i < n; i++)
    {
        dp[i][0][0] = std::max({dp[i][0][0], 1LL * a[i], dp[i - 1][0][0] + a[i] * 1LL, dp[i - 1][1][1] + 1LL * a[i]});

        dp[i][1][0] = std::max({dp[i][1][0], 1LL * a[i], dp[i - 1][1][0] + 1LL * a[i]});

        dp[i][1][1] = std::max({dp[i][1][1], 1LL * x * a[i], dp[i - 1][1][1] + 1LL * x * a[i], dp[i - 1][1][0] + 1LL * x * a[i]});

        ans = std::max({ans, dp[i][0][0], dp[i][1][1], dp[i][1][0]});
    }

    std::cout << ans;

    return 0;
}