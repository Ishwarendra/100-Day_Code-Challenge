#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution 
{
public:
    int minimumSeconds(std::vector<int>& nums) 
    {
        int n = std::size(nums);
        int ans = n - 1;

        std::map<int, std::vector<int>> pos;
        for (int i = 0; i < n; i++)
            pos[nums[i]].emplace_back(i);

        for (auto &[num, p] : pos)
        {
            int cur_ans = 0;
            for (int i = 1; i < std::size(p); i++)
                cur_ans = std::max(cur_ans, (p[i] - p[i - 1]) / 2);

            int d1 = p.front();
            int d2 = n - p.back();

            cur_ans = std::max(cur_ans, (d1 + d2) / 2);
            ans = std::min(ans, cur_ans);
        }

        return ans;
    }
};

int main()
{
    return 0; 
}    