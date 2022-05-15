#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;

// Bottom-Up solution
/*
Find solution for f(i, j) where i and j denote the range of element we are considering to get best answer
then we use range of smaller size to get answer for bigger range
*/

class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        vvi dp(n, vi(n));

        // Base-Cases
        if (n == 1)
            dp[0][0] = nums[0];
        else
            dp[0][0] = nums[0] * nums[1];

        // Gap = 0
        for (int i = 1; i < n; i++)
        {
            dp[i][i] = nums[i - 1] * nums[i];
            dp[i][i] *= (i + 1 < n) ? nums[i + 1] : 1;
        }

        for(int gap = 1; gap < n; gap++)
        {
            for(int i = 0; i < n - gap; i++)
            {
                int j = i + gap;
                for(int k = i; k <= j; k++)
                {
                    int cur_point = 1;

                    cur_point *= nums[k];
                    cur_point *= (i - 1 < 0) ? 1 : nums[i - 1];
                    cur_point *= (j + 1 >= n) ? 1 : nums[j + 1];

                    cur_point += (k - 1 < 0) ? 0 : dp[i][k - 1];
                    cur_point += (k + 1 >= n) ? 0 : dp[k + 1][j];

                    dp[i][j] = max(dp[i][j], cur_point); 
                }
            }
        }

        return dp[0][n - 1];
    }
};

int main()
{
    return 0;
}