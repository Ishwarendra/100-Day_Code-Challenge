#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
#define printarr(v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v) for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << a << " ";
    err(++it, args...);
};

void solve()
{
	int n, l, k;
	cin >> n >> l >> k;
	
	vi a(n), d(n + 1);
	d[n] = l; 
	
	for(int i = 0; i < n; i++)
		cin >> d[i];
	for(int i = 0; i < n; i++)
		cin >> a[i];
		
	if (n == 1)
	{
		cout << a[0] * l << "\n";
		return;	
	}
		
	vvi dp(n + 1, vi(n + 1, 1e9));

	dp[0][0] = 0;	
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			for(int k = i + 1; k <= n; k++)
			{
				int dist = d[k] - d[i];
				dp[k][j + 1] = min(dp[k][j + 1], dist*a[i] + dp[i][j]);
			}
		}
	}
	
	int ans = 1e9;
	for(int i = n; i >= n - k; i--)
		ans = min(ans, dp[n][i]);
	
	cout << ans << "\n";
}

int main()
{
    FIO;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}