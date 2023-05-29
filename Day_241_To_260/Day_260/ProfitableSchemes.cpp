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
    int profitableSchemes(int n, int minProfit, std::vector<int>& group, std::vector<int>& profit) 
    {
        auto add = [&](int &x, int y) { x = (x + y) % MOD; };
        int m = std::size(group);

        std::vector dp(minProfit + 1, std::vector(n + 1, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; i++)
        {
            auto ndp = dp;
            for (int p = 0; p <= minProfit; p++)
            {
                for (int x = 0; x <= n; x++)
                {
                    if (x + group[i] > n)
                        continue;

                    add(ndp[std::min(p + profit[i], minProfit)][x + group[i]], dp[p][x]); 
                }
            }

            std::swap(dp, ndp);
        }

        int ans = 0;
        for (int x = 0; x <= n; x++)
            ans = (ans + dp[minProfit][x]) % MOD;
        return ans;
    }
};

int main()
{
    return 0; 
}    