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

int n, m;
vvi grid;

bool within_bound(int x, int y)
{
	return (y >= 0 and y < m) and (x >= 0 and x < n);
}

bool perform_operation(int i, int j)
{
	// Direction in following order
	// int left = 0, leftdu = 0, leftdd = 0;
	// int right = 0, rightdu = 0, righdd = 0;
	// int up = 0, down = 0;
	
	vi dx {-1, -1, -1, 1, 1, 1, 0, 0};
	vi dy {0, 1, -1, 0, 1, -1, 1, -1};
	
	vi direction(8);
	
	for(int d = 0; d < 8; d++)
	{
		if (within_bound(i + dx[d], j + dy[d]))
			direction[d] = grid[i + dx[d]][j + dy[d]];
	}
	
	// Left left-dia-up Down
	int a = 0, b = 1, c = 6;
	if (direction[a] * direction[b] * direction[c])
		return false;
	
	// Right right-dia-up Up
	a = 3, b = 4, c = 6;
	if (direction[a] * direction[b] * direction[c])
		return false;
	
	// Left left-dia-down Down
	a = 0, b = 2, c = 7;
	if (direction[a] * direction[b] * direction[c])
		return false;
	
	// Right right-dia-down Down
	a = 3, b = 5, c = 7;
	if (direction[a] * direction[b] * direction[c])
		return false;
	
	return true;
}

void solve()
{
	cin >> n >> m;
	
	grid.assign(n, vi(m, 0));
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			char ch; cin >> ch;
			grid[i][j] = ch - '0';
		}
	}
	
	
	bool possible = true;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			// For each white check if its diagonal is all black or not
			// Treat out of bound as white (check if all its diagonal are black or not)
			if (grid[i][j] == 0)
			{
				possible &= perform_operation(i, j);
			}	
		}
	}
	
	if (possible)
		cout << "YES\n";
	else
		cout << "NO\n";
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