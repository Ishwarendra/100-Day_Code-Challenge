#include <bits/stdc++.h>
using namespace std;

#define FIO        ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a)     ((a).begin()), ((a).end())
#define printarr   (v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v)     for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define int        long long
#define fps(x, y)  fixed<<setprecision((y))<<(x)
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

using ll       =    long long;
using vi       =    vector<int>;
using vvi      =    vector<vector<int>>;
using ld       =    long double;
using pii      =    pair<int, int>;
using mii      =    map<int, int>;
using umii     =    unordered_map<int, int>;
using maxheap  =    priority_queue<int>;
using minheap  =    priority_queue<int, vector<int>, greater<int>>;

void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << a << " ";
    err(++it, args...);
};

// W S E N
vi di {0, 1, 0, -1},
   dj {-1, 0, 1, 0};

int n, m; 

void dfs(int i, int j, vvi &vis, vvi &grid, int &ans)
{
    // print("here", i, j, vis[i][j]);
    if (i < 0 || j < 0 || i >= n || j >= m || vis[i][j])
        return;
    ans++;
    vis[i][j] = 1;
    
    for(int pos = 0; pos < 4; pos++)
    {
        if (((grid[i][j] >> pos) & 1) == 0)
          dfs(i + di[pos], j + dj[pos], vis, grid, ans);  
    }
}

void solve()
{
    cin >> n >> m;
    
    vvi grid(n, vi(m));
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];
    }
    
    vi ans;
    vvi vis(n, vi(m, 0));
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int cur = 0;
            if (not vis[i][j])
            {
                // print(i, j);
                dfs(i, j, vis, grid, cur);
                ans.push_back(cur);
            }
        }
    }
    
    sort(all(ans), greater<int>());
    
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}

int32_t main()
{
    FIO;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}