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
    int minIncrements(int n, std::vector<int>& cost)
    {
        std::vector<int> sum(n);
        int max = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            int x = i;
            sum[i] = cost[x];
            while (x)
                x = (x - 1) / 2, sum[i] += cost[x];

            max = std::max(max, sum[i]);
            if (i < n / 2)
                sum[i] = std::max(sum[2 * i + 1], sum[2 * i + 2]);       
        }

        int ans = 0;
        std::vector<int> lazy(n);

        auto push = [&](int x)
        {
            if (x < n / 2)
            {
                lazy[2 * x + 1] += lazy[x];
                lazy[2 * x + 2] += lazy[x];
            }

            lazy[x] = 0;
        };

        for (int i = 0; i < n; i++)
        {
            sum[i] += lazy[i];
            lazy[i] += max - sum[i];
            push(i);
            ans += max - sum[i];
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
    std::cout << sol.minIncrements(n, a);
    return 0;
}