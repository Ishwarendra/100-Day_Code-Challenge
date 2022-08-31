#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

class Solution 
{
public:
    int countRangeSum(std::vector<int>& nums, int lower, int upper) 
    {
        int n = std::size(nums);
        std::vector<i64> pref(n);        
        pref[0] = nums[0];

        for (int i = 1; i < n; i++)
            pref[i] = pref[i - 1] + nums[i];

        i64 ans = 0;
        int l = -1, r = -1;

        auto good = [&](int mid, int id)
        {
            i64 sum = pref[mid] - (id - 1 >= 0 ? pref[id - 1] : 0LL);
            return lower <= sum and sum <= upper; 
        };

        auto binSearch = [&](int id)
        {
            int left = id, right = n - 1;
            int index = -1;

            while (left <= right)
            {
                int mid = (left + right) >> 1;

                if (good(mid, id))
                    index = mid, left = mid + 1;
                else
                    right = mid - 1;
            }

            return index;
        };

        auto intersect = [&](int st, int en) -> int
        {
            if (r < st or en < l)
                return 0;

            return std::min(r, en) - st + 1;
        };

        for (int i = 0; i < n; i++)
        {
            int next = binSearch(i);
            int sub = intersect(i, next);

            ans += 1LL * (next - i + 1) * (next - i + 2) / 2;
            ans -= 1LL * sub * (sub + 1) / 2;
            l = i, r = next;
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    int n, lower, upper;
    std::cin >> n >> lower >> upper;

    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        std::cin >> nums[i];

    std::cout << sol.countRangeSum(nums, lower, upper);
    return 0; 
}    