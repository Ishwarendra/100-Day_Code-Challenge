#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution {
public:
    int numSubarraysWithSum(std::vector<int>& nums, int goal) 
    {
        int n = std::size(nums);    

        std::vector<int> ones;
        ones.emplace_back(-1);
        for (int i = 0; i < n; i++)
        {
            if (nums[i])
                ones.emplace_back(i);
        }

        ones.emplace_back(n);
        int sz = std::size(ones);
        int ans = 0;

        if (goal == 0)
        {
            for (int i = 1; i < sz; i++)
            {
                int zeroes = ones[i] - ones[i - 1];
                ans += 1LL * zeroes * (zeroes - 1) / 2;
            }
            
            return ans;
        }

        for (int l = 1; l < sz; l++)
        {   
            int r = l + goal - 1;
            if (r >= sz - 1)
                break;

            int left = (ones[l] - ones[l - 1]);
            int right = (ones[r + 1] - ones[r]);

            ans += left * right;
        }

        return ans;
    }   
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, goal;
    std::cin >> n >> goal;

    std::vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
        std::cin >> nums[i];

    Solution sol;
    std::cout << sol.numSubarraysWithSum(nums, goal);
    
    return 0;
}