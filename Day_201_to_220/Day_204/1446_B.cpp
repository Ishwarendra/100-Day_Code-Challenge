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
    
    int n, m;
    std::cin >> n >> m;

    std::string s, t;
    std::cin >> s >> t;

    std::vector dp(n + 1, std::vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = std::max(0, dp[i - 1][j - 1] + 2);
            else
                dp[i][j] = std::max({dp[i][j], dp[i - 1][j] - 1, dp[i][j - 1] - 1});
        }
    }

    int ans = 0;
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
            ans = std::max(ans, dp[i][j]);
    }

    std::cout << ans;
    
    return 0;
}