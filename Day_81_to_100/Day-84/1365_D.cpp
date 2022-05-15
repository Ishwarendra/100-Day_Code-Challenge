#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define all(a)      ((a).begin()), ((a).end())
#define log(v)      for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
// #define int         long long
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

int dx[] {1, -1, 0, 0};
int dy[] {0, 0, 1, -1};

int n, m;
char grid[51][51];
bool can_go[51][51];

bool bound(int i, int j)
{
	return i >= 0 and j >= 0 and i < n and j < m;
}

bool block(int i, int j)
{
	for (int d = 0; d < 4; d++)
	{
		int new_x = i + dx[d], new_y = j + dy[d];
		
		if (not bound(new_x, new_y))
			continue;
				
		if (bound(new_x, new_y) and grid[new_x][new_y] == 'G')
			return false;
				
		if (grid[new_x][new_y] == 'B')
			continue;
		else
			grid[new_x][new_y] = '#';		
	}
	
	return true;
}

void solve()
{
	cin >> n >> m;
		
	for (int i = 0; i < n; i++)
		cin >> grid[i];
	
	// If bad at last cell then impossible
	if (grid[n - 1][m - 1] == 'B')
	{
		cout << "No\n";
		return;
	}
	
	// Block all Bad
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (grid[i][j] == 'B')
			{
				bool possible = block(i, j);
				
				if (not possible)
				{
					std::cout << "No\n";
					return;
				}				
			}
		}
	}
	
	memset(can_go, false, sizeof can_go);
	
	// Check if you can reach from (n-1, m-1) to all Good People
	queue<pii> q;
	
	if (grid[n - 1][m - 1] != '#')
		q.emplace(n - 1, m - 1);
	
	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		
		can_go[cur.first][cur.second] = true;
		
		for (int i = 0; i < 4; i++)
		{
			int x = cur.first + dx[i], y = cur.second + dy[i];
			
			if (not bound(x, y))
				continue;
			
			if (can_go[x][y] != false)
				continue;
			
			if (grid[x][y] != '#')
				q.emplace(x, y);
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (grid[i][j] == 'G' and can_go[i][j] == false)
			{
				cout << "No\n";
				return;
			}
		}
	}
	
	cout << "Yes\n";
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