#include <bits/stdc++.h>
using namespace std;

constexpr int inf = 1e9 + 10;

bool bfs(vector<vector<int>> &rg, int u, int v, vector<int> p)
{
    deque<int> q;
    vector<int> vis(rg.size());

    q.push_back(u);

    while (!q.empty())
    {
        u = q.front();
        q.pop_front();

        vis[u] = 1;

        for (int i = 0; i < rg[u].size(); i++) 
        {
            if (!vis[i] && rg[u][i] > 0) 
            {
                p[i] = u;
                q.push_front(i);
                if (i == v) 
                    return true;
            }
        }
    }

    return false;
}

string solve(int N, int K, vector<int> c, vector<string> p)
{
    map<std::string, int> nm;
    int n = 1; // not capital N

    for (int i = 0; i < N; ++i)
        nm["s" + i] = n++;

    for (int i = 0; i < c.size(); ++i)
        for (int j = 0; j < c[i]; ++j)
            nm["c" + i + j] = n++;

    n++;

    vector<std::vector<int>> g(n, std::vector<int>(n));
    for (int i = 1; i <= N; ++i)
        g[0][i] = 1;

    for (int i = N + 1; i < n - 1; i++)
        g[i][n - 1] = 1;

    int pos = 0;
    for (auto pref : p)
    {
        int x = 0, y = 0;
        int i = 0;
        for (i = 0; i < pref.size(); i++)
        {
            if (pref[i] == ',')
                break;
            x = x * 10 + pref[i] - '0';
        }

        for (; i < pref.size(); i++)
        {
            if (pref[i] == ',')
                continue;
            y = y * 10 + pref[i] - '0';
        }

        for (int k = 0; k < c[x]; k++)
        {
            g[nm["s" + i]][nm["c" + x + k]] = 1;
            g[nm["s" + i]][nm["c" + x + k]] = 1;
        }

        for (int k = 0; k < c[y]; k++)
        {
            g[nm["s" + i]][nm["c" + y + k]] = 1;
            g[nm["s" + i]][nm["c" + y + k]] = 1;
        }

        pos++;
    }

    vector<vector<int>> rg(n, std::vector<int>(n));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            rg[i][j] = g[i][j];
    }

    vector<int> parent(n);
    int max_flow = 0;

    int cnt = 0;

    while (bfs(rg, 0, n - 1, parent))
    {
        cnt++;

        int path_flow = inf;
        for (int i = n - 1; i != 0; i = parent[i])
            path_flow = min(path_flow, rg[parent[i]][i]);

        max_flow = max_flow + path_flow;
        for (int i = n - 1; i != 0; i = parent[i])
        {
            rg[parent[i]][i] -= path_flow;
            rg[i][parent[i]] += path_flow;
        }
    }

    return (max_flow == N ? "YES" : "NO");
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;

    std::vector<int> cap(k);
    std::vector<std::string> pref(n);
    for (int i = 0; i < k; ++i)
        std::cin >> cap[i];

    for (int i = 0; i < n; ++i)
        std::cin >> pref[i];

    print(pref)

    std::cout << solve(n, k, cap, pref) << "\n";
    return 0;
}