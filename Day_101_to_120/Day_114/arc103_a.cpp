#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define all(a)      ((a).begin()), ((a).end())
#define log(v)      for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define int         long long
#define fps(x, y)   fixed<<setprecision((y))<<(x)

#define printarr(v, start, end) for(int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

using ll       =    long long;
using vi       =    vector<int>;
using vvi      =    vector<vector<int>>;
using vpii     =    vector<pair<int, int>>;
using ld       =    long double;
using pii      =    pair<int, int>;
using mii      =    map<int, int>;
using umii     =    unordered_map<int, int>;
using pbds     =    tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T>
using maxheap  =    priority_queue<T>;
template<typename T>
using minheap  =    priority_queue<T, vector<T>, greater<T>>;

template<typename T1, typename T2> istream &operator >> (istream& in, pair<T1, T2> &a)
{in >> a.first >> a.second; return in;}
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> &a)
{out << a.second << ":" << a.first; return out;}
void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{cout << a << " "; err(++it, args...);};

constexpr int inf = 7e18;

void solve()
{
	int n; cin >> n;
	
	vi a(n);
	map<int, int> even , odd;
	
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		if (i % 2 == 0)
			even[a[i]]++;
		else
			odd[a[i]]++;
	}
	
	auto get_max_freq = [&](map<int, int> &m) 
	{
		vector<pair<int, int>> options;
		
		for (auto &i : m)
			options.push_back({i.second, i.first});
			
		sort(all(options), greater<pii>());
		
		if (options.size() < 2)
			return options;
		
		return vpii(options.begin(), options.begin() + 2);
	};	
	
	vector<vpii> f(2);
	f[0] = get_max_freq(even); 
	f[1] = get_max_freq(odd);
	
	if (f[0][0].second != f[1][0].second)
		cout << n - (f[0][0].first + f[1][0].first);
	else
	{
		if (f[0].size() == 1 and f[1].size())
			cout << n/2;
		else
		{
			if (f[0].size() == 1)
				cout << n - (f[0][0].first + f[1][1].first);
			else if (f[1].size() == 1)
				cout << n - (f[0][1].first + f[1][0].first);
			else
			{
				cout << n - max(f[0][1].first + f[1][0].first,
					f[1][1].first + f[0][0].first);
			}
		}
	}
}

int32_t main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int t = 1;
	// std::cin >> t;
	
	for(int i = 1; i <= t; i++)
	{
		// std::cout << "Case #" << i << ": ";
		solve();
	}
	
	return 0;
}
/* credits: harasees_singh :maaf_karo:
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/