#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;

class Solution
{
    vi dy{1, 0, -1};

    // n  -> x range; m -> y range
    int f(int x, int y1, int y2, vector<vvi> &dp, int n, int m, vvi &grid)
    {

        // Out of bounds check
        if (x >= n or y1 >= m or y2 >= m or y1 < 0 or y2 < 0)
        {
            return -1e7;
        }

        // if already checked this  state
        if (dp[x][y1][y2] != -1)
            return dp[x][y1][y2];

        int result = grid[x][y1];
        if (y1 != y2)
            result += grid[x][y2];
        int cur_max = 0;
        if (x != n - 1)
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    cur_max = max(cur_max, f(x + 1, y1 + dy[i], y2 + dy[j], dp, n, m, grid));
                }
            }

            result += cur_max;
        }

        return dp[x][y1][y2] = result;
    }

public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int x = grid.size(), y = grid[0].size();
        vector<vvi> dp(x, vvi(y, vi(y, -1)));
        // f(x, y1, y1, dp, x_range, y_range)
        return f(0, 0, y - 1, dp, x, y, grid);
    }
};

int main()
{
    return 0;
}