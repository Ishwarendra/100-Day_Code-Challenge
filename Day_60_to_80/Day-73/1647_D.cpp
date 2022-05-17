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

bool isPrime(int n)
{
	if (n < 2)
		return false;
	for (int x : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
	{
		if (n == x)
			return true;
		bool flag = true;
		int r = 1;
		int t = 1;
		while (r <= ((n - 1) >> __builtin_ctzll(n - 1)))
		{
			if (r & ((n - 1) >> __builtin_ctzll(n - 1)))
				t = ((int)t * x) % n;
			x = ((int)x * x) % n;
			r <<= 1;
		}
		if (t == 1 || t == n - 1)
			flag = false;
		for (r = 0; r < __builtin_ctzll(n - 1); r++)
		{
			t = ((int)t * t) % n;
			if (t == n - 1)
				flag = false;
		}
		if (flag)
			return false;
	}
	return true;
}

bool prime_factor(int x)
{
	set<int> factor;
	
	for(int i = 1; i * i <= x; i++)
	{
		if (x % i == 0)
			factor.emplace(i);
		
		if (i != x/i)
			factor.emplace(x/i);
	}
	
	factor.erase(1);
	factor.erase(x);
	
	for(int i : factor)
}

void solve()
{
	int x, d;
	cin >> x >> d;

	int k = x / d;

	if (k % (d * d) == 0)
	{
		int tmp = k / (d * d);

		if (not isPrime(tmp))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	else
		cout << "NO\n";
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