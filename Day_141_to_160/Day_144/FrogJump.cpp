#include <bits/stdc++.h>
using namespace std;

#define LOCAL 1

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

class Solution {
public:
    bool canCross(vector<int>& stones) 
    {
        int n = stones.size();
        
        if (stones[1] != 1)
            return false;
        
        std::vector<std::vector<int>> dp(n, std::vector<int>(n + 2));    

        dp[0][0] = 1, dp[1][1] = 1;

        for (int i = 1; i < n - 1; i++)
        {
            for (int k = 1; k < n; k++)
            {
                if (dp[i][k])
                {
                    int can = std::binary_search(stones.begin(), stones.end(), stones[i] + k + 1);
                    int id = std::lower_bound(stones.begin(), stones.end(), stones[i] + k + 1) - stones.begin();
                    if (id != n)
                        dp[id][k + 1] = can;

                    can = std::binary_search(stones.begin(), stones.end(), stones[i] + k);
                    id = std::lower_bound(stones.begin(), stones.end(), stones[i] + k) - stones.begin();
                    if (id != n)
                        dp[id][k] = can;

                    can = std::binary_search(stones.begin(), stones.end(), stones[i] + k - 1);
                    id = std::lower_bound(stones.begin(), stones.end(), stones[i] + k - 1) - stones.begin();
                    if (id != n)
                        dp[id][k - 1] = can;
                }
            }
        }

        int ans = 0;

        for (int i : dp[n - 1])
            ans |= i;

        return ans;
    }
};

int main()
{
    return 0; 
}    