#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())

using vi = vector<int>;
using vll = vector<long long>;
using ll = long long;

ll ans = 0;
int tc = 1, n;

int dfs(int cur, const vector<list<pair<int, int>>> &adj , vector<bool> &vis, vector<int> &count)
{
    vis[cur] = true;

    for(pair<int, int> nb : adj[cur])
    {
        if (!vis[nb.first])
        {
            count[cur] += dfs(nb.first, adj, vis, count);
            int left = count[nb.first];
            int right = n - left;
            // cout << "Added: " << 2*min(left, right)*nb.second << "\n";
            ans += 2 * min(left, right) * nb.second;
        }
    }

    return count[cur];
}

void solve()
{
    cin >> n;
    vector<list<pair<int, int>>> adj(n + 1); // vertex1 -> (vertex2, cost) 

    // Preparing the graph
    for(int i = 0; i < n - 1; i++)
    {
        int u, v, cost;
        cin >> u >> v >> cost;
        adj[u].push_back({v, cost});
        adj[v].push_back({u, cost});
    }

    // Make visited and count vector
    vector<bool> vis(n + 1, false);
    vector<int> count(n + 1, 1); 
    
    // Reset answer
    ans = 0;
    dfs(1, adj, vis, count);

    cout << "Case #" << tc++ << ": " << ans << "\n";
}

int main()
{
    FIO
    int t = 1;
    cin >> t;
    while(t--)
          solve();
    return 0;
}