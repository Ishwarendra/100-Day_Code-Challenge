#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

int solve(std::vector<std::vector<int>>& matrix) 
{
    int n = std::size(matrix);
    if (n == 0)
        return 0;
    int m = std::size(matrix[0]);

    std::vector<std::vector<int>> d(n, std::vector<int>(m, -1));

    std::queue<std::pair<int, int>> q;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (matrix[i][j] == 2)
            {
                d[i][j] = 0;
                q.emplace(i, j);
            }
        }
    }

    auto safe = [&](int i, int j)
    {
        return i >= 0 and j >= 0 and i < n and j < m;
    };

    std::vector<std::pair<int, int>> dirs
    {
        {0, 1}, {1, 0}, {-1, 0}, {0, -1}
    };  

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy] : dirs)
        {
            int i = x + dx, j = y + dy;
            if (safe(i, j) and d[i][j] == -1 and matrix[i][j] != 0)
            {
                q.emplace(i, j);
                d[i][j] = d[x][y] + 1;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; ++j)
        {
            if (matrix[i][j] != 0 and d[i][j] == -1)
                return -1;

            ans = std::max(ans, d[i][j]);
        }
    }

    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> mat(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            std::cin >> mat[i][j];

    std::cout << solve(mat);
    
    return 0;
}