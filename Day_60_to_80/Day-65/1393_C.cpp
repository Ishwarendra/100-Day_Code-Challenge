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

template<typename T1, typename T2> 
istream &operator >> (istream& in, pair<T1, T2> &a)
{
	in >> a.first >> a.second; return in;
}

template<typename T1, typename T2> 
ostream &operator << (ostream& out, pair<T1, T2> &a)
{
	out << a.first << " " << a.second; return out;
}

void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << a << " ";
    err(++it, args...);
};

bool good(int mid, set<pii, greater<pii>> m, int n)
{	
	int start = 0, prev = 0;
	for(auto i : m)
	{
		int freq = i.first;
		for(int j = 0; j < freq - 1; j++)
			prev += mid;
		
		start++;
		
		if (start >= n or prev >= n)
			return false;
		
		prev = start;
	}
	
	return (start < n and prev < n);
}

void solve()
{
	int n; cin >> n;
	
	map<int, int> m;
	set<pii, greater<pii>> s;
	
	for(int i = 0; i < n; i++)
	{
		int x; cin >> x;
		m[x]++;
	}
	
	for(auto i : m)
		s.insert({i.second, i.first});
	
	int left = 1, right = n;
	int ans = -1;
	
	while(left <= right)
	{
		int mid = (left + right)/2;
		
		if (good(mid, s, n))
			ans = mid, left = mid + 1;
		else
			right = mid - 1;		
	}
	
	print(ans - 1);			
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