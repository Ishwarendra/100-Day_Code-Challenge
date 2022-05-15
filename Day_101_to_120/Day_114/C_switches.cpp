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

int n, m;
vvi s;
vi p;
int ans = 0;

int common_switches(vi &a, vi &b)
{
	// both vector are sorted
	vi temp(100, -1);
	set_intersection(all(a), all(b), temp.begin());
	int sz = 0;
	for (int i = 0; i < temp.size(); i++, sz++)
	{
		if (temp[i] == -1)
			break;
	}
	
	return sz;
}

void f(int id, vector<int> &on)
{
	if (id == n)
	{
		sort(all(on));
		bool all_on = true;
		
		for (int i = 0; i < m; i++)
		{
			if (common_switches(s[i], on) % 2 != p[i])
			{
				all_on = false;					
				break;
			}
		}
		
		if (all_on)
			ans++;
		
		return;
	}
	
	// turn on
	on.push_back(id);
	f(id + 1, on);
	on.pop_back();
	
	// keep off
	f(id + 1, on);
}

void solve()
{
	cin >> n >> m;
	
	// s[0][1] => 2nd switch ke on hone se affected
	s.resize(m);
	
	for (int i = 0; i < m; i++)
	{
		int k; cin >> k;
		
		for (int j = 0; j < k; ++j)
		{
			int x; cin >> x;
			s[i].push_back(--x);
		}
		
		sort(all(s[i]));
	}
	
	p.resize(m); // ith switch is on if (total_on) % 2 == p[i]
	
	for (int i = 0; i < m; i++)
		cin >> p[i];
	
	vi on;
	f(0, on);
	
	cout << ans;
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