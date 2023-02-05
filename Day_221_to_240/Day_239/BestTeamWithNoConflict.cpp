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
    int bestTeamScore(std::vector<int>& scores, std::vector<int>& ages) 
    {
        int n = std::size(scores);
        std::vector a(n + 1, std::array {0, 0});

        for (int i = 0; i < n; i++)
            a[i + 1] = {ages[i], scores[i]};

        std::sort(std::begin(a), std::end(a));

        std::vector<int> dp(n + 1, 0);
        dp[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (a[i][1] < a[j][1])
                    continue;

                dp[i] = std::max(dp[i], dp[j] + a[i][1]);
            }
        }

        return *std::max_element(std::begin(dp), std::end(dp));
    }
};


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    for (int i = 0; i < n; i++)
        std::cin >> b[i];

    Solution sol;
    std::cout << sol.bestTeamScore(a, b);
    
    return 0;
}