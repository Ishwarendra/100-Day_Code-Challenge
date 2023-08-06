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
    int maxValue(std::vector<std::vector<int>>& events, int k) 
    {
        int n = std::size(events);
        std::sort(std::begin(events), std::end(events), [&](auto &event1, auto &event2)
        {
            return event1[1] < event2[1];
        });

        std::vector dp(n, std::vector(k + 1, 0));
        std::fill(std::begin(dp[0]), std::end(dp[0]), events[0][2]);
        dp[0][0] = 0;

        std::map<int, int> last;
        last[events[0][1]] = 0;

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                dp[i][j] = std::max({dp[i][j], dp[i][j - 1], dp[i - 1][j], events[i][2]});

                auto it = last.lower_bound(events[i][0]);

                if (it == std::begin(last) or j - 1 < 0)
                    continue;

                it--;
                dp[i][j] = std::max(dp[i][j], dp[it->second][j - 1] + events[i][2]);
            }

            last[events[i][1]] = i;
        }

        return dp.back().back();
    }
};

int main()
{
    Solution sol;
    int n;
    std::cin >> n;

    std::vector a(n, std::vector<int>(3));
    for (int i = 0; i < n; i++)
        std::cin >> a[i][0] >> a[i][1] >> a[i][2];

    int k;
    std::cin >> k;

    std::cout << sol.maxValue(a, k);
    return 0; 
}       