#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution {
public:
    int subarraysDivByK(std::vector<int>& nums, int k) 
    {
        int n = std::size(nums);

        int p = 0;
        int ans = 0;

        std::vector<int> cnt(k);
        cnt[0]++;
        for (int i = 0; i < n; i++)
        {
            p += nums[i];
            p = (p % k + k) % k;
            ans += cnt[p];
            cnt[p]++;

        }
        
        return ans;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    Solution sol;
    int n, k;
    std::cin >> n >> k;

    std::vector<int> nums(n);
    for (int i = 0; i < n; i++)
        std::cin >> nums[i];

    std::cout << sol.subarraysDivByK(nums, k);
    
    return 0;
}