#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
#define printarr(v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v) for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

using vi = vector<int>;
using vvi = vector<vector<int>>;
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

vi *adj;
// red = 0, black = 1;
vi col;

void dfs(int cur, int c, vi &vis)
{
    vis[cur] = true;
    col[cur] = c;
    for(int nb : adj[cur]){
        
        if (not vis[nb]){
            dfs(nb, 1 - c, vis);  
        }
    }
}

void solve()
{
    col.clear();
    
    int n, m; cin >> n >> m;
    adj = new vi[n + 1];
    
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    col.resize(n + 1);
    
    vi vis(n + 1);
    dfs(1, 0, vis);

    int red = count(all(col), 0) - 1;
    int black = n - red;
    
    if (red <= black){
        cout << red << "\n";
        for(int i = 1; i < col.size(); i++)
            if (col[i] == 0)
                cout << i << " ";
    }
    else{
        cout << black << "\n";
        for(int i = 1; i < col.size(); i++)
            if (col[i] == 1)
                cout << i << " ";    
    }
    
    cout << "\n";
    
    delete[] adj;
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