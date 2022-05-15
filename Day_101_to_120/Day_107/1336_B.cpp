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
void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{cout << a << " "; err(++it, args...);};

constexpr int inf = 7e18;

int sq(int x)
{
	return x * x;
}

int f(int x, int y, int z)
{
	return sq(x - y) + sq(z - x) + sq(y - z);
}

void solve()
{
	vi n(3);
	
	for (int i = 0; i < 3; i++)
		cin >> n[i];
	
	vvi gems(3);
	
	for (int i = 0; i < 3; i++)
	{
		gems[i].resize(n[i]);
		
		for (int j = 0; j < n[i]; ++j)
			cin >> gems[i][j];
		
		sort(all(gems[i]));
	}
	
	auto get = [&](vi &order)
	{
		vi &a = gems[order[0]];
		vi &b = gems[order[1]];
		vi &c = gems[order[2]];
		
		// x -> a y -> b z -> c
		int ans = inf;
		
		for (int y : b)
		{
			auto x = lower_bound(all(a), y);
			auto z = upper_bound(all(c), y);
			
			if (x == a.end() or z == c.begin())
				continue;
			z--;
			
			ans = min(ans, f(*x, y, *z));
		}
		
		return ans;
	};
	
	vi order {0, 1, 2};
	int ans = inf;
	
	do 
	{
		ans = min(ans, get(order));
		
	} while (next_permutation(all(order)));
	
	cout << ans << "\n";
}

int32_t main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int t = 1;
	std::cin >> t;
	
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