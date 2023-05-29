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
    int power(int a, int b)
    {
        int res = 1;
        for (; b; b /= 2, a = (1LL * a * a) % MOD)
        {
            if (b % 2)
                res = (1LL * res * a) % MOD;
        }
        return res;
    }     
public:
    int numSubseq(std::vector<int>& nums, int target) 
    {
        int n = std::size(nums);
        std::sort(std::begin(nums), std::end(nums));
        int ans = 0;
        for (int i = 0; i < n; i++)    
        {
            int id = std::upper_bound(std::begin(nums), std::end(nums), target - nums[i]) - std::begin(nums);
            if (id - i - 1 >= 0)
                ans = (ans + (2 * nums[i] <= target) * power(2, id - i - 1)) % MOD;
        }   

        return ans;
    }
};

int main()
{
    return 0; 
}    