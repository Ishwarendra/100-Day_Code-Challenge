#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution {
public:
    i64 minCost(std::vector<int>& nums, std::vector<int>& cost) 
    {
        int n = std::size(nums);
        std::vector<i64> p(n + 1), q(n + 1);    

        std::vector a(n, std::array<int, 2>());
        for (int i = 0; i < n; i++)
            a[i] = {nums[i], cost[i]};
        std::sort(std::begin(a), std::end(a));

        for (int i = 0; i < n; i++)
            nums[i] = a[i][0], cost[i] = a[i][1];

        std::sort(std::begin(nums), std::end(nums));

        for (int i = 0; i < n; i++)
            p[i + 1] = p[i] + cost[i];
        for (int i = 0; i < n; i++)
            q[i + 1] = q[i] + 1LL * nums[i] * cost[i];

        auto get = [&](int x, int i)
        {
            return 1LL * x * (2 * p[i] - p[n]) + (q[n] - 2 * q[i]);
        };

        i64 ans = 1e18;
        int min = nums[0], max = nums.back();
        for (int x = min; x <= max; x++)
        {
            auto i = std::upper_bound(std::begin(nums), std::end(nums), x) - std::begin(nums);
            ans = std::min(ans, get(x, i));
        }       

        return ans;
    }
};

int main()
{
    return 0; 
}    