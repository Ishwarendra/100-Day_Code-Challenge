#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution {
public:
    std::vector<std::vector<int>> findSubsequences(std::vector<int>& nums) 
    {
        std::set<std::vector<int>> ans;
        int n = std::size(nums);

        for (int mask = 0; mask < (1 << n); mask++)    
        {
            if (__builtin_popcount(mask) <= 1)
                continue;

            std::vector<int> a;
            int ok = 1;
            for (int i = 0; i < n; i++)
            {
                if ((mask >> i) & 1)
                {
                    if (a.empty() or nums[i] >= a.back())
                        a.emplace_back(nums[i]);
                    else
                        ok = 0;
                }
            }

            if (ok)
                ans.emplace(a);
        }

        return std::vector<std::vector<int>>(std::begin(ans), std::end(ans));
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    
    
    return 0;
}