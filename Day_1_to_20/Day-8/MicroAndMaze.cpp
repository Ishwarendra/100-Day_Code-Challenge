#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
using vi = vector<int>;
using ll = long long;

int dx[] {1, -1, 0, 0};
int dy[] {0, 0, 1, -1};
int n, m;


bool possible(vector<vi> &maze, int x, int y, vector<vector<bool>> &vis)
{
    if (x >= m or x < 0 or y >= n or y < 0)
        return false;
    if (maze[x][y] == 0 or vis[x][y])
        return false;
    return true;
}

void solve_maze(vector<vi> &maze, int x, int y, vector<vector<bool>> &vis, bool &ans)
{
    // Base-Cases
    if (x == m - 1 and y == n - 1)
    {
        ans = true;
        return;
    }

    // Iterate over choices
    for(int i = 0; i < 4; i++)
    {
        if (possible(maze, x + dx[i], y + dy[i], vis))
        {
            //Do some task
            vis[x + dx[i]][y + dy[i]] = true;
            
            // call function in next state
            solve_maze(maze, x + dx[i], y + dy[i], vis, ans);

            // Undo the task
            vis[x + dx[i]][y + dy[i]] = false;
        }
    }

    return;
}

int main()
{
    cin >> n >> m;

    vector<vi> maze(n, vi(m));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cin >> maze[i][j];
    }

    vector<vector<bool>> vis(n, vector<bool>(m, false));

    bool ans = false;
    solve_maze(maze, 0, 0, vis, ans);

    if (ans)
        cout << "Yes\n";
    else 
        cout << "No\n"; 

    return 0;
}