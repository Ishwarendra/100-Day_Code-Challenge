#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution 
{
    const int MOD = 1e9 + 7;
public:
    int numMusicPlaylists(int n, int goal, int k) 
    {
        std::vector dp(goal + 1, std::vector(n + 1, 0));            
        dp[0][0] = 1;

        for (int i = 1; i <= goal; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (j > 0) 
                {
                    dp[i][j] += (dp[i - 1][j - 1] * std::max<i64>(0, n - j + 1)) % MOD;
                    dp[i][j] %= MOD;
                }

                dp[i][j] += (1LL * dp[i - 1][j] * std::max(0, j - k)) % MOD;
                dp[i][j] %= MOD;
            }
        }
        
        return dp[goal][n];
    }
};

int main()
{
    Solution sol;
    int n, goal, k;
    std::cin >> n >> goal >> k;

    std::cout << sol.numMusicPlaylists(n, goal, k);

    return 0; 
}    