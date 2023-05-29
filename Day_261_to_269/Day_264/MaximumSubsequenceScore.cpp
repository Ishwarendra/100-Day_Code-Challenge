#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

struct DS
{
    std::multiset<int> m;
    i64 sum;
    int k;

    DS(int k) : sum(0), k(k) {}
    bool add(int x)
    {   
        if (std::size(m) < k)
        {
            sum += x;
            m.emplace(x);
            return true;
        }
        if (*std::begin(m) > x)
            return false;

        sum += x - *std::begin(m);
        m.erase(std::begin(m));
        m.emplace(x);
        return true;
    }
    i64 get() { return sum * (std::size(m) == k); }
};

class Solution 
{
public:
    i64 maxScore(std::vector<int>& nums1, std::vector<int>& nums2, int k) 
    {
        int n = std::size(nums1);
        std::vector<int> order(n);
        std::iota(std::begin(order), std::end(order), 0);

        std::sort(std::begin(order), std::end(order), [&](int i, int j)
        {
            if (nums2[i] == nums2[j])
                return nums1[i] > nums1[j];
            return nums2[i] > nums2[j];
        });

        i64 ans = 0;
        DS ds(k);
        int min = nums2[order[0]];

        for (int i : order)
        {
            if (ds.add(nums1[i]))
                min = std::min(min, nums2[i]);
            ans = std::max(ans, ds.get() * min);
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    for (int i = 0; i < n; i++)
        std::cin >> b[i];

    std::cout << sol.maxScore(a, b, k);
    return 0; 
}    