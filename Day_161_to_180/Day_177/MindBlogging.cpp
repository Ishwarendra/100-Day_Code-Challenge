#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

int solve(std::vector<std::vector<std::string>> & matrix, std::vector<std::string>& words)
{
    int n = std::size(matrix);
    int m = std::size(matrix[0]);

    auto find = [&](std::string &a)
    {
        auto safe = [&](int i, int j)
        {
            return i >= 0 and j >= 0 and i < n and j < m;
        };

        std::vector<std::pair<int, int>> dirs
        {
            {0, 1}, {1, 0}, {0, -1}, { -1, 0}, {1, 1}, { -1, -1}, { -1, 1}, {1, -1}
        };

        std::vector<std::vector<bool>> vis(n, std::vector<bool>(m));

        std::function<bool(int, int, int)> dfs = [&](int st, int en, int id) -> bool
        {
            if (id + 1 == std::size(a))
                return true;
            vis[st][en] = 1;

            for (auto [dx, dy] : dirs)
            {
                int i = st + dx, j = en + dy;
                if (safe(i, j) and !vis[i][j] and matrix[i][j] == std::string(1, a[id + 1]))
                {
                    bool can = dfs(i, j, id + 1);
                    if (can)
                        return true;
                }
            }

            return false;
        };

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == std::string(1, a[0]))
                {
                    if (dfs(i, j, 0))
                        return true;

                    std::fill(std::begin(vis), std::end(vis),
                              std::vector<bool>(m));
                }
            }
        }

        return false;
    };

    int ans = 0;
    for (auto &word : words)
    {
        ans += find(word);
    }

    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::string>> matrix(n, std::vector<std::string>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            std::cin >> matrix[i][j];

    int num;
    std::cin >> num;
    std::vector<std::string> words(num);

    for (int i = 0; i < num; ++i)
        std::cin >> words[i];

    std::cout << solve(matrix, words);

    return 0;
}