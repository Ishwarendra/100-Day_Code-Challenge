#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution 
{
    const int MOD = 1e9 + 7;
public:
    int numWays(std::vector<std::string>& words, std::string target) 
    {
        int n = std::size(words[0]);
        int m = std::size(target);

        std::vector cnt(n, std::array<int, 26>{});       
        for (auto word : words)
        {
            for (int i = 0; i < n; i++)
                cnt[i][word[i] - 'a']++;
        }

        std::vector dp(n + 1, std::vector(m + 1, 0));
        auto mul = [&](int a, int b)
        {
            int ans = (1LL * a * b) % MOD;
            return ans;
        };
        
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for (int j = 1; j <= m; j++)
        {
            for (int i = 1; i <= n; i++)
            {
                int ch = target[j - 1] - 'a';
                dp[i][j] = mul(dp[i - 1][j - 1], cnt[i - 1][ch]) + dp[i - 1][j];
                dp[i][j] %= MOD;
            }
        }

        return dp[n][m];
    }
};

int main()
{
    Solution sol;
    int n;
    std::cin >> n;

    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::string target;
    std::cin >> target;

    std::cout << sol.numWays(a, target);

    return 0; 
}    