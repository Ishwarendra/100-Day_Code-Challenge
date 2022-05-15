#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
#define printarr(v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v) for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

using vi = vector<int>;
using vll = vector<long long>;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
      cout << a << " ";
      err(++it, args...);
};

void dfs(int cur, int par, int wt, vi &ans, vector<list<pii>> &adj)
{
      for(pii nb : adj[cur])
      {
            if (nb.first != par){
                  ans[nb.second] = wt;
                  dfs(nb.first, cur, 5 - wt, ans, adj);
            }
      }
}

void solve()
{
      int n; cin >> n;
      vector<list<pii>> adj(n); // X -> (Y, wt)
      for(int i = 0; i < n - 1; i++)
      {
            int u, v; cin >> u >> v;
            --u, --v;
            adj[u].push_back({v, i});
            adj[v].push_back({u, i});
      }

      int root = -1;
      bool possible = true;
      for(int i = 0; i < n; i++)
      {
            if (adj[i].size() == 1)
                  root = i;
            if (adj[i].size() > 2)
                  possible = false;
      }
      if (not possible)
            cout << "-1\n";
      else
      {
            vi ans(n - 1);
            dfs(root, -1, 2, ans, adj);
            for(int i : ans)
                  cout << i << " ";
            cout << "\n";
      }
}

int main()
{
      FIO;
      int t = 1;
      cin >> t;
      while(t--)
          solve();
      return 0;
}