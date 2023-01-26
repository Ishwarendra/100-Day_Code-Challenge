#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution {
public:
    int snakesAndLadders(std::vector<std::vector<int>>& board)
    {
        int n = std::size(board);
        std::vector<int> a(n * n);

        std::reverse(std::begin(board), std::end(board));
        for (int i = 0; i < n; i++)
        {
            if (i % 2)
                std::reverse(std::begin(board[i]), std::end(board[i]));

            for (int j = 0; j < n; j++)
                a[i * n + j] = board[i][j];
        }

        std::vector<int> vis(n * n, -1);
        std::queue<int> q;
        q.push(0);
        vis[0] = 0;

        while (!q.empty())
        {
            auto x = q.front();
            q.pop();

            int d = vis[x];

            for (int i = 1; i <= 6 and x + i < n * n; i++)
            {
                if (a[x + i] == -1 and vis[x + i] == -1)
                {
                    vis[x + i] = d + 1;
                    q.push(x + i);
                }
                else if (a[x + i] != -1)
                {
                    if (vis[a[x + i] - 1] == -1)
                    {
                        vis[a[x + i] - 1] = d + 1;
                        q.push(a[x + i] - 1);
                    }
                }
            }
        }
        
        return vis.back();
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // int n;
    // std::cin >> n;

    // std::vector a(n, std::vector<int>(n));
    // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < n; j++)
    //         std::cin >> a[i][j];

    // std::vector<std::vector<int>> a {
    //     { -1, -1, -1, 46, 47, -1, -1, -1}, {51, -1, -1, 63, -1, 31, 21, -1}, { -1, -1, 26, -1, -1, 38, -1, -1}, { -1, -1, 11, -1, 14, 23, 56, 57}, {11, -1, -1, -1, 49, 36, -1, 48}, { -1, -1, -1, 33, 56, -1, 57, 21}, { -1, -1, -1, -1, -1, -1, 2, -1}, { -1, -1, -1, 8, 3, -1, 6, 56}
    // };

    std::vector<std::vector<int>> a {
        {-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,35,-1,-1,13,-1},{-1,-1,-1,-1,-1,-1},{-1,15,-1,-1,-1,-1}
    };


    Solution sol;
    std::cout << sol.snakesAndLadders(a);

    return 0;
}