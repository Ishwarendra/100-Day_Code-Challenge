#include <bits/stdc++.h>
using namespace std;

#define FIO       ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a)    ((a).begin()), ((a).end())
#define printarr  (v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v)    for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};
#define int       long long

using vi   =  vector<int>;
using vvi  =  vector<vector<int>>;
using vll  =  vector<long long>;
using vvll =  vector<vector<long long>>;
using ll   =  long long;
using ld   =  long double;
using ull  =  unsigned long long;
using pii  =  pair<int, int>;
using pll  =  pair<long long, long long>;

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

	vi low(3, 1e18), high(3, 1e18), diff(2, 1e18);

	for (int i = 0; i < n; i++)
	{
		int l, r, c;
		cin >> l >> r >> c;

		low  = min(low, {l, c, r});  // lowest int and lowest cost first
		high = min(high, { -r, c, l}); // highest r and lowest cost;
		diff = min(diff, {l - r, c}); // max diff and lowest cost

		int ans = 1e18;

		int range = 0;

		// log(low);
		// log(high);
		// log(diff);

		if (-diff[0] > range)
			range = -diff[0], ans = diff[1];

		if (-high[0] - low[0] >= range and (low[2] == -high[0] and low[0] == high[2] and low[1] == high[1]))
		{
			if (-high[0] - low[0] == range)
				ans = min(ans, low[1]);
			else
				ans = low[1];
		}
		else if (-high[0] - low[0] >= range)
		{
			if (-high[0] - low[0] == range)
				ans = min(ans, low[1] + high[1]);
			else
				ans = low[1] + high[1];
		}


		cout << ans << "\n";
	}

}

int32_t main()
{
	FIO;
	int t = 1;
	cin >> t;
	while (t--)
		solve();
}