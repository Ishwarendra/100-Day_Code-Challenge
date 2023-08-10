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
    int minimizeMax(std::vector<int>& nums, int p)
    {
        int n = std::size(nums);
        std::sort(std::begin(nums), std::end(nums));

        auto good = [&](int mid)
        {
            int cnt = 0;
            for (int i = 0; i + 1 < n; i++)
            {
                if (nums[i + 1] - nums[i] <= mid)
                    i++, cnt++;
            }

            return cnt >= p;
        };

        int left = 0, right = nums.back() - nums.front();
        int ans = -1;

        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (good(mid))
                ans = mid, right = mid - 1;
            else
                left = mid + 1;
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    int n, p;
    std::cin >> n >> p;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::cout << sol.minimizeMax(a, p);

    return 0;
}