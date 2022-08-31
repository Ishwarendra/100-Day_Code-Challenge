#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution {
    const int inf = 1e9;
public:
    int minCost(int n, std::vector<int>& cuts) 
    {
        cuts.push_back(0);
        cuts.push_back(n);
        int sz = std::size(cuts);
        std::vector dp(sz, std::vector<int>(sz, inf));    

        std::sort(std::begin(cuts), std::end(cuts));

        for (int i = 0; i < sz; i++)
        {
            dp[i][i] = 0;
            if (i + 1 < sz)
                dp[i][i + 1] = 0;
        }

        for (int len = 2; len < sz; len++)
        {
            for (int i = 0; i < sz; i++)
            {
                int j = i + len;
                for (int k = i + 1; k < j; k++)
                    dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j] + cuts[j] - cuts[i]);
            }
        }

        return dp[0][sz - 1];
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, sz;
    std::cin >> sz >> n;
    
    std::vector<int> cuts(sz);
    for (int i = 0; i < sz; ++i)
        std::cin >> cuts[i];

    Solution sol;
    std::cout << sol.minCost(n, cuts);

    return 0;
}