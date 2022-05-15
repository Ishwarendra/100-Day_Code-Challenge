#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define all(a)     ((a).begin()), ((a).end())
#define log(v)     for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define int        long long
#define fps(x, y)  fixed<<setprecision((y))<<(x)

#define printarr(v, start, end) for(int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
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
{in >> a.first >> a.second; return in;}
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> &a)
{out << a.first << " " << a.second; return out;}
void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{cout << a << " "; err(++it, args...);};

vi fact;

void preprocess()
{
	int x = 1, n = 1;
	
	while(x <= 1e12 + 2)
	{
		fact.push_back(x);
		x *= n;
		n++;
	}
}

int set_bits(int x)
{
	int cnt = 0;
	
	for(int i = 0; i < 40; i++)
	{
		if ((x >> i) & 1)
			cnt++;
	}
	
	return cnt;
}

int f(int n, int i)
{
	int ans = set_bits(n);
	
	for(; i < fact.size(); i++)
	{
		if (n - fact[i] >= 0)
			ans = min(ans, f(n - fact[i], i + 1) + 1);
	}
	
	return ans;
}

void solve()
{
	int n; cin >> n;
	cout << f(n, 1) << "\n";
}

int32_t main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	preprocess();
	
	int t = 1;
	cin >> t;
	
	for(int i = 1; i <= t; i++)
	{
		// cout << "Case #" << i << ": ";
		solve();
	}
	
	return 0;
}