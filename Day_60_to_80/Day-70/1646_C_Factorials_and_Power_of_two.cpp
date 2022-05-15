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

constexpr int m = 40;

vector<int> fact;
set<pii> sum;

int get_bit(int x, int pos)
{
	return (x >> pos) & 1;
}

void prepare_sum(int &cur_sum, int i, int how_many)
{
	if (i == fact.size())
	{
		sum.insert({cur_sum, how_many});
		return;
	}
	
	prepare_sum(cur_sum, i + 1, how_many);
	
	cur_sum += fact[i];
	
	prepare_sum(cur_sum, i + 1, how_many + 1);
	
	cur_sum -= fact[i];
}

void preprocess()
{
	int x = 1, n = 1;
	
	while(x <= 1e12 + 2)
	{
		fact.push_back(x);
		x *= n;
		n++;
	}
	
	// int cur_sum = 0;
	
	// prepare_sum(cur_sum, 0, 0);
}

int set_bits(int x)
{
	int cnt = 0;
	
	for(int i = 0; i < m; i++)
	{
		if ((x >> i) & 1)
			cnt++;
	}
	
	return cnt;
}

void solve()
{
	int n; cin >> n;
	
	int ans = 40;
	
	for(int i = 0; i < (1 << 15); i++)
	{
		int old_n = n;
		
		for(int j = 0; j < fact.size(); j++)
		{
			if (get_bit(i, j))
				n -= fact[j];
		}
		
		ans = min(ans, set_bits(i) + set_bits(n));
		
		n = old_n;
	}
	
	cout << ans << "\n";
}

int32_t main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	preprocess();
	
	// int n = 20;
	
	// for(auto i : sum)
	// {
	// 	cout << i << "& ";
	// 	n--;
	// 	if (n == 0)
	// 		break;
	// }
	
	int t = 1;
	cin >> t;
	
	for(int i = 1; i <= t; i++)
	{
		// cout << "Case #" << i << ": ";
		solve();
	}
	
	return 0;
}