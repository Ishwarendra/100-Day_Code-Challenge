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
{in >> a.first >> a.ssecond; return in;}
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> &a)
{out << a.first << " " << a.ssecond; return out;}
void err(istream_iterator<string> it) {};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{cout << a << " "; err(++it, args...);};

void solve()
{
	string s; cin >> s;

	int n = s.length();

	int two_dig_id = 0, two_dig_sum = 0;

	bool two = false;

	for (int i = 0; i < n - 1; i++)
	{
		int cur_sum = s[i] + s[i + 1] - '0' - '0';

		if (cur_sum >= 10)
		{
			two_dig_id = i, two_dig_sum = cur_sum;
			two = true;
		}
	}

	int one_dig_id = 0, one_dig_sum = 0;

	for (int i = 0; i < n - 1; i++)
	{
		int cur_sum = s[i] + s[i + 1] - '0' - '0';

		if (cur_sum < 10)
		{
			one_dig_id = i, one_dig_sum = cur_sum;
			break;
		}
	}

	if (two)
	{	
		for (int i = 0; i < n; i++)
		{
			if (i == two_dig_id)
			{
				cout << two_dig_sum;
				i++;
			}

			else
				cout << s[i];
		}

		cout << "\n";
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (i == one_dig_id)
			{
				cout << one_dig_sum;
				i++;
			}

			else
				cout << s[i];
		}

		cout << "\n";
	}
}

int32_t main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	cin >> t;

	for (int i = 1; i <= t; i++)
	{
		// cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}