#include<bits/stdc++.h>

using namespace std;

#define LOCAL 1

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

std::vector<std::vector<int>> dirs 
{
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}
};

bool can = false;

void dfs(vector<vector<char>> &board, string &s, int i, int j, int k)
{
    int n = board.size(), m = board[0].size();
    if (k == s.size())
    {
        can = true;
        return;
    }

    auto safe = [&n, &m](int i, int j)
    {
        return i >= 0 and j >= 0 and i < n and j < m;
    };

    for (auto dir : dirs)
    {
        int x = i + dir[0], y = j + dir[1];

        if (safe(x, y) and s[k] == board[x][y])
        {
            char ch = board[x][y];
            board[x][y] = '!';
            dfs(board, s, x, y, k + 1);
            board[x][y] = ch;
        }
    }
}

bool hasPath(vector<vector<char>> &board, string &s)
{
    int n = board.size();
    int m = board[0].size();
    can = false;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (board[i][j] == 'C')
            {
                print(i, j)
                dfs(board, s, i, j, 1);
            }
        }
    }
    
    return can;
}

int main()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<char>> board(n, std::vector<char>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            std::cin >> board[i][j];
    }

    std::string s;
    std::cin >> s;

    std::cout << std::boolalpha << hasPath(board, s);
    
    return 0;
}