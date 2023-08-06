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
    int minimumDifference(std::vector<int>& a) 
    {
        std::map<int, std::set<int>> left, right;
        int n = std::size(a) / 2;    

        std::array<int, 2> total{};
        for (int i = 0; i < 2 * n; i++)
            total[i < n] += a[i];

        for (int mask = 0; mask < (1 << n); mask++)        
        {
            int sum = 0;
            for (int i = 0; i < n; i++)
                sum += a[i] * (mask >> i & 1);
            left[__builtin_popcount(mask)].emplace(total[0] - 2 * sum);
        }

        for (int mask = 0; mask < (1 << n); mask++)
        {
            int sum = 0;
            for (int i = 0; i < n; i++)
                sum += a[i + n] * (mask >> i & 1);
            right[__builtin_popcount(mask)].emplace(total[1] - 2 * sum);
        }

        int ans = std::abs(total[1] - total[0]);
        for (int len = 0; len <= n; len++)
        {   
            for (auto d1 : left[len])
            {
                auto it = right[n - len].lower_bound(-d1);
                if (it != std::end(right[n - len]))
                    ans = std::min(ans, std::abs(d1 + *it));
                if (it != std::begin(right[n - len]))
                    ans = std::min(ans, std::abs(d1 + *std::prev(it)));
            }
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
    std::cout << sol.minimumDifference(a);
    return 0; 
}    