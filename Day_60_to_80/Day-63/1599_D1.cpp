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

class DSU
{
    int *par, *rnk;
    int _connected;

public:
    DSU(int n)
    {
        par = new int[n];
        rnk = new int[n];
        _connected = n;

        for (int i = 0; i < n; i++)
            par[i] = i, rnk[i] = 1;
    }

    ~DSU()
    {
        delete[] par;
        delete[] rnk;
    }

    int get(int x)
    {
        if (par[x] == x)
            return x;
        return par[x] = get(par[x]);
    }

    int unite(int x, int y)
    {
        int p1 = get(x), p2 = get(y);
        if (p1 != p2)
        {
            if (rnk[p1] > rnk[p2])
                par[p2] = p1, rnk[p1] += rnk[p2],rnk[p2] = 0;
            else
                par[p1] = p2, rnk[p2] += rnk[p1], rnk[p1] = 0;
            
            return 1;
            
        }
        return 0;
    }
    
    bool same(int x, int y)
    {
    	return get(x) == get(y);
    }
    
    int num_of_ele(int x)
    {
    	return rnk[get(x)];
    }
}; 

void solve()
{
	int n, m1, m2;
	cin >> n >> m1 >> m2;
	
	DSU mocha(n), diana(n);
		
	for(int i = 0; i < m1; i++)
	{
		int u, v; cin >> u >> v;
        u--, v--;
		mocha.unite(u, v);
	}
	
	for(int i = 0; i < m2; i++)
	{
		int u, v; cin >> u >> v;
        u--, v--;
		diana.unite(u, v);
	}
	
	int ans = 0;
    vector<pii> edges;
	
	for(int u = 0; u < n - 1; u++)
	{
		for(int v = u + 1; v < n; v++)
		{
			if (diana.get(u) != diana.get(v) and mocha.get(u) != mocha.get(v))
            {
                edges.push_back({u + 1, v + 1});
                diana.unite(u, v);
                mocha.unite(u, v);
				ans++;
            }
		}
	}
	
	cout << ans << "\n";
    for(int i = 0; i < edges.size(); i++)
        print(edges[i].first, edges[i].second);
}

int32_t main()
{
    FIO;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}