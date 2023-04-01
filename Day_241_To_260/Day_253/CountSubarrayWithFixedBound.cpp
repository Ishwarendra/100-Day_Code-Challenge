#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution 
{
public:
    i64 countSubarrays(std::vector<int>& nums, int minK, int maxK) 
    {
        int n = std::size(nums);

        int min = -1, max = -1, outOfBound = -1;
        i64 ans = 0;
        for (int i = 0; i < n; i++)        
        {
            if (nums[i] < minK or nums[i] > maxK)
                outOfBound = i;

            if (nums[i] == minK)            
                min = i;
            if (nums[i] == maxK)
                max = i;

            if (outOfBound >= std::min(min, max))
                continue;   

            // print(i, ans, min, max, outOfBound)
            ans += std::min(min, max) - outOfBound;
        }

        return ans;
    }
};

int main()
{
    int n, minK, maxK;
    std::cin >> n >> minK >> maxK;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    Solution sol;
    std::cout << sol.countSubarrays(a, minK, maxK);
    return 0; 
}    