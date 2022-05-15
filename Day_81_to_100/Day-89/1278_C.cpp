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
{out << a.first << " " << a.second; return out;}
void err(istream_iterator<string> it) {};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{cout << a << " "; err(++it, args...);};

void solve()
{
	int n, d = 0; cin >> n;

	vi a(2 * n), diff(2 * n);
	map<int, int> m;

	for (int i = 0; i < 2 * n; i++)
	{
		cin >> a[i];
		d += (a[i] == 1 ? -1 : 1);
	}
	
	reverse(all(a) - n);

	for (int i = 0; i < n; i++)
	{
		diff[i] = (a[i] == 1 ? -1 : 1); // type2 - type1

		if (i)
			diff[i] += diff[i - 1];
	}

	int ans = 2 * n;

	for (int i = n; i < 2 * n; i++)
	{
		diff[i] = (a[i] == 1 ? -1 : 1);
		if (i > n)
			diff[i] += diff[i - 1];
	}
	
	for (int i = 2 * n - 1; i >= n; i--)
		m[diff[i]] = i - n;
	
	m[0] = -1;
		
	// eat 0 from start
	int type_2_rem = d;
	int j;
	
	if (m.find(type_2_rem) != m.end())
	{
		j = m[type_2_rem];
		ans = min(ans, j + 1);
	}	
	
	for (int i = 0; i < n; i++)
	{
		// remove first i from start
		// to remove [n .. n + j - 1]
		type_2_rem = d - diff[i];
		
		if (m.find(type_2_rem) == m.end())
			continue;
		
		j = m[type_2_rem];

		ans = min(ans, i + 1 + j + 1);
	}

	print(ans);
}

int32_t main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;

	for (int i = 1; i <= t; i++)
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