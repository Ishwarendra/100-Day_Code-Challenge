#include <bits/stdc++.h>
using namespace std;

#define LOCAL 1

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(...) 1;
#define print(...) 1;
#endif

class Solution
{
    const int mod;
public:
    Solution() : mod(int(1e9) + 7) {}
    int kInversePairs(int n, int k)
    {
        if (k > n * (n - 1) / 2)
            return 0;

        std::vector<int> dp(k + 1);
        dp[0] = 1;

        for (int i = 2; i <= n; ++i)
        {
            std::vector<int> ndp(k + 1), pref(k + 1);
            pref[0] = dp[0];
            ndp[0] = 1;

            for (int _ = 1; _ <= k; _++)
                pref[_] += ((pref[_ - 1] % mod) + (dp[_] % mod)) % mod;

            for (int j = 1; j <= k; j++)
            {
                // only (i - 1) increase possible
                // dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] + ... + dp[i - 1][j - i + 1 or 0];
                int en = std::max(0, j - i + 1);
                ndp[j] = (pref[j] - (en == 0 ? 0 : pref[en - 1])) % mod;
            }

            // print(ndp, pref)
            std::swap(dp, ndp);
        }
        if (dp[k] < 0)
            dp[k] += mod;
        
        return dp[k];
    }
};

int main()
{
    int n, k;
    std::cin >> n >> k;

    Solution sol;
    std::cout << sol.kInversePairs(n, k);
    return 0;
}