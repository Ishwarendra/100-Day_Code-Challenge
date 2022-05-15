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

const int inf = 9e18;

int sq(int x)
{
	return x * x;
}

int f(int x, int y, int z)
{
	return sq(x - y) + sq(y - z) + sq(z - x);
}

int optimal_ans(vvi &gems, vi &id)
{
	// x(1) <= y(0) <= z(2) 
	
	int ans = inf;
	
	for(int y : gems[id[1]])
	{
		// y -> known, x -> just smaller or eq than y, z -> just bigger than y
		int x_id = upper_bound(all(gems[id[0]]), y) - gems[id[0]].begin();
		x_id--;
		
		int z_id = lower_bound(all(gems[id[2]]), y) - gems[id[2]].begin();
		
		if (z_id == gems[id[2]].size())
			z_id--;
		if (x_id < 0)
			x_id = 0;
		
		ans = min(ans, f(y, gems[id[0]][x_id], gems[id[2]][z_id]));
	}
	
	return ans;
}

void solve()
{
	vi n(3);
	cin >> n[0] >> n[1] >> n[2];
	
	vvi gems(3);
	
	for(int i = 0; i < 3; i++)
	{
		gems[i].resize(n[i]);
		
		for(int j = 0; j < n[i]; j++)
			cin >> gems[i][j];
			
		sort(all(gems[i]));
	}
	
	int ans = inf;
	vi id {0, 1, 2};
	
	do 
	{
		ans = min(ans, optimal_ans(gems, id));
		
	} while (next_permutation(all(id)));
	
	std::cout << ans << "\n";
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