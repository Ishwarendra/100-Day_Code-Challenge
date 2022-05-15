#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define FIO        ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a)     ((a).begin()), ((a).end())
#define printarr   (v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v)     for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define int        long long
#define fps(x, y)  fixed<<setprecision((y))<<(x)
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

template<typename T1, typename T2> istream &operator >> (istream& in, pair<T1, T2> &a) {in >> a.first >> a.ssecond; return in;}
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> &a) {out << a.first << " " << a.ssecond; return out;}
void err(istream_iterator<string> it) {};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
	cout << a << " ";
	err(++it, args...);
};

void solve()
{
	int n; cin >> n;

	vi a(n), vis(n + 1);

	multiset<int, greater<int>> in_hand;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] <= n and not vis[a[i]])
			vis[a[i]] = true;
		else
			in_hand.insert((a[i] + 1) / 2 - 1);
	}

	int steps = 0;

	for (int need = n; need >= 1; need--)
	{
		if (not vis[need])
		{
			if (in_hand.empty())
			{
				cout << "-1\n";
				return;
			}

			auto have = in_hand.begin();
			if (*have >= need)
			{
				in_hand.erase(have);
				vis[need] = true;
				steps++;
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (not vis[i])
		{
			cout << "-1\n";
			return;
		}
	}

	cout << steps << "\n";
}

int32_t main()
{
	FIO;
	int t = 1;
	cin >> t;
	while (t--)
		solve();

	return 0;
}