#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution 
{
    const int N = 1001;
    const int offset = N / 2;
public:
    int longestArithSeqLength(std::vector<int>& nums) 
    {
        int n = std::size(nums);
        std::map<int, std::vector<int>> pos;
        pos[nums[0]].emplace_back(0);

        std::vector dp(n, std::vector(N, 1));
        for (int i = 1; i < n; i++)
        {
            for (int d = -500; d <= 500; d++)
            {
                if (!pos.count(nums[i] - d))
                    continue;

                int D = d + offset;
                for (int j : pos[nums[i] - d])
                    dp[i][D] = std::max(dp[i][D], dp[j][D] + 1);
            }

            pos[nums[i]].emplace_back(i);
        }

        int ans = 1;
        for (int i = 0; i < n; i++)
            ans = std::max(ans, *std::max_element(std::begin(dp[i]), std::end(dp[i])));

        return ans;
    }
};

int main()
{
    return 0; 
}    