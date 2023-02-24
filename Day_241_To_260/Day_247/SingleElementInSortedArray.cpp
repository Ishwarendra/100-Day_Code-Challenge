#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution {
public:
    int singleNonDuplicate(std::vector<int>& nums) 
    {
        int n = std::size(nums);
        int left = 0, right = n - 1;

        auto duplicateId = [&](int i)
        {
            if (i + 1 < n and nums[i + 1] == nums[i])
                return i + 1;
            if (i - 1 >= 0 and nums[i - 1] == nums[i])
                return i - 1;

            return -1;
        };

        auto good = [&](int mid)
        {
            // auto [min, max] = std::minmax(mid, duplicateId(mid));
            int min = std::min(mid, duplicateId(mid));
            int max = std::max(mid, duplicateId(mid));
            if (min == -1)
                return 0;

            if (min % 2 == 0)
                return 1;

            return -1;
        };

        int ans = -1;


        while (left <= right)
        {
            int mid = (left + right) >> 1;
            auto res = good(mid);

            if (res == 0)
            {
                ans = nums[mid];
                break;
            }
            else if (res == 1)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return ans;
    }
};

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    Solution sol;
    std::cout << sol.singleNonDuplicate(a);
    return 0; 
}    