#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
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
using pbds     =    tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T1, typename T2> istream &operator >> (istream& in, pair<T1, T2> &a){in >> a.first >> a.ssecond; return in;}
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> &a){out << a.first << " " << a.ssecond; return out;}
void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << a << " ";
    err(++it, args...);
};

const int inf = 2e18;

int sq(int x)
{
	return x*x;
}

int f(int x, int y, int z)
{
	return sq(x - y) + sq(y - z) + sq(z - x);
}

int get_min(vi &a, vi &b, vi &c)
{
	int best_sum = inf;
	// a[i] <= b[i] <= c[i]
	for(int y : b)
	{
		vi::iterator x = lower_bound(all(a), y);
				
		if (*x != y and x != a.begin())
			x--;
		
		vi::iterator z = lower_bound(all(c), y);
		
		if (*z != y and z == c.end())
			z--;
		
		best_sum = min(best_sum, f(*x, y, *z));
	}
	
	return best_sum;
}

void solve()
{
	vi n(3);
	vvi weights(3);
	
	for(int i = 0; i < 3; i++)
		cin >> n[i];
	
	for(int i = 0; i < 3; i++)
	{
		weights[i].resize(n[i]);
		
		for(int j = 0; j < n[i]; j++)
			cin >> weights[i][j];
		
		sort(all(weights[i]));
	}
	
	int best_sum = inf;
	
	vi id {0, 1, 2};
	
	do
	{
		int cur_sum = get_min(weights[id[0]], weights[id[1]], weights[id[2]]);	
		best_sum = min(best_sum, cur_sum);
	} 
	while(next_permutation(all(id)));
	
	cout << best_sum << "\n";
}

int32_t main()
{
	FIO;
	int t = 1; 
	cin >> t;
	while(t--)
		solve();
	
	return 0;
}