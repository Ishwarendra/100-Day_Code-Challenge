#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

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
using pbds     =    tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T1, typename T2> istream &operator >> (istream& in, pair<T1, T2> &a)
{in >> a.first >> a.ssecond; return in;}
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> &a)
{out << a.first << " " << a.ssecond; return out;}
void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{cout << a << " "; err(++it, args...);};

class DSU
{
    int *par, *rnk;
    int _connected;

public:
    DSU(int n)
    {
        par = new int[n], rnk = new int[n], _connected = n;
        for (int i = 0; i < n; i++)
            par[i] = i, rnk[i] = 1;
    }

    ~DSU()
    {
        delete[] par; delete[] rnk;
    }

    int get(int x)
    {
        if (par[x] == x) return x;
        return par[x] = get(par[x]);
    }

    bool unite(int x, int y)
    {
        int p1 = get(x), p2 = get(y);
        if (p1 == p2)
            return false;
        else
        {
            par[p2] = max(par[p1], par[p2]);
            par[p1] = par[p2];
            
            return true;
        }
    }
    
    bool same(int x, int y)
    {
    	return (get(x) == get(y));
    }
}; 

void solve()
{
	int n, q;
	std::cin >> n >> q;
	
	std::vector<int> l(q), r(q), c(q);
	
	for(int i = q - 1; i >= 0; i--)
	{
		std::cin >> l[i] >> r[i] >> c[i];
		l[i]--, r[i]--;
	}
		
	DSU d(n + 1);
	
	std::vector<int> col(n + 1);
	
	for(int i = 0; i < q; i++)
	{
		int start = d.get(l[i]), end = r[i];
		while(start <= end)
		{
			col[start] = c[i];
			d.unite(start, start + 1);
			start = d.get(start);
		}
	}
	
	for(int i = 0; i < n; i++)
		cout << col[i] << "\n";
}

int32_t main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int t = 1;
	// cin >> t;
	
	for(int i = 1; i <= t; i++)
	{
		// cout << "Case #" << i << ": ";
		solve();
	}
	
	return 0;
}