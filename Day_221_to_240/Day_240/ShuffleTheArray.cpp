#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution {
public:
    std::vector<int> shuffle(std::vector<int>& nums, int n) 
    {
        std::vector<int> ans;
        for (int i = 0; i < n; i++)    
        {
            ans.emplace_back(nums[i]);
            ans.emplace_back(nums[i + n]);
        }

        return ans;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    
    
    return 0;
}