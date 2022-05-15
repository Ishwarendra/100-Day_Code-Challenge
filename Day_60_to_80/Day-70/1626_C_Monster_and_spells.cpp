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

bool intersect(pii &a, pii &b)
{
	return b.first < a.second;
}

void unite(vector<pii> &interval, pii &a, pii &b)
{
	if (b.first < a.second)
	{
		int start = a.first, end = b.second;
		
		interval.push_back({start, end});
	}
}

void solve()
{
	int n; cin >> n;
	
	vi k(n), h(n);
	
	for(auto &_ : k)
		cin >> _;
	
	for(auto &_ : h)
		cin >> _;
	
	if (n == 1)
	{
		cout << (h[0]) * (h[0] + 1) /2 << "\n"; 
		return;
	}
	
	vector<pii> minter(n), intervals;
	
	for(int i = 0; i < n; i++)
	{
		int start = k[i] - h[i];
		int end = k[i];
		
		minter[i] = {start, end};
	}
	
	sort(all(minter));
	
	int start = minter[0].first, end = minter[0].second;
	
	for(int i = 0; i < n - 1;)
	{
		if (intersect(minter[i], minter[i + 1]))
		{
			start = min(start, minter[i].first);
			end = max(end, minter[i + 1].second);
			i++;
		}
		else
		{
			intervals.push_back({start, end});
			intervals.push_back({minter[i + 1].first, minter[i + 1].second});
			
			if (i + 2 < n)
				start = minter[i + 2].first,
				end = minter[i + 2].second;
			
			i += 2;
		}
	}
	
	// print("yo")
	intervals.push_back({start, end});
	
	n = intervals.size();
	
	int mana = 0;
	
	for(int i = 0; i < n; i++)
	{
		int len = intervals[i].second - intervals[i].first;
		
		mana += len * (len + 1) /2;
	}
	
	cout << mana << "\n";
}

int32_t main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int t = 1;
	cin >> t;
	
	for(int i = 1; i <= t; i++)
	{
		// cout << "Case #" << i << ": ";
		solve();
	}
	
	return 0;
}