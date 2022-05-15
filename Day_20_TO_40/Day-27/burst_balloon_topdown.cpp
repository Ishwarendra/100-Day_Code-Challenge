#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;

// Top-Down approach

class Solution {
    vvi dp;
    
    int f(int i, int j, vi &a)
    {
        int n = a.size();
        if (i < 0 or i > n or j < 0 or j > n or i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];
        
        for(int k = i; k <= j; k++)
        {
            int cur_point = 1;

            cur_point *= a[k];
            cur_point *= (i - 1 < 0) ? 1 : a[i - 1];
            cur_point *= (j + 1 >= n) ? 1 : a[j + 1];

            cur_point += (f(i, k - 1, a) + f(k + 1, j, a));

            dp[i][j] = max(cur_point, dp[i][j]);
        }

        return dp[i][j];
    }

public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, vi(n, -1));   
        return f(0, n - 1, nums); 
    }
};

int main()
{
    return 0;
}