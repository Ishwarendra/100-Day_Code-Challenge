#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution 
{
    const int inf = 1e9;
public:
    int jump(std::vector<int>& nums) 
    {
        int n = std::size(nums);
        std::vector<int> dp(n, inf);    
        
        dp[0] = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < std::min(n, i + nums[i] + 1); j++)
                dp[j] = std::min(dp[j], dp[i] + 1);
        }

        return (dp.back() == inf ? -1 : dp.back());
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    Solution sol;
    std::cout << sol.jump(a);
    
    return 0;
}