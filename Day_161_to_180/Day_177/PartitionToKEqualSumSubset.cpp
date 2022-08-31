#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

class Solution {
    std::vector<int> dp;
public:
    bool canPartitionKSubsets(std::vector<int>& nums, int k) 
    {
        int need = std::accumulate(std::begin(nums), std::end(nums), 0);

        if (need % k) 
            return false;
        need /= k;

        int n = std::size(nums);
        dp.resize(1 << n, -1);

        dp[0] = 0;
        for (int mask = 0; mask < std::size(dp); mask++)
        {
            if (dp[mask] == -1)
                continue;

            for (int i = 0; i < n; i++)
            {
                int vis = (mask >> i) & 1;
                if (!vis and dp[mask] + nums[i] <= need)
                {
                    dp[mask | (1 << i)] = dp[mask] + nums[i];

                    if (dp[mask | (1 << i)] == need)
                        dp[mask | (1 << i)] = 0;
                }
            }
        }

        // for (auto i : dp)
        //     print(i)

        return dp[(1 << n) - 1] == 0;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    Solution sol;
    std::cout << std::boolalpha << sol.canPartitionKSubsets(a, k);
    
    return 0;
}