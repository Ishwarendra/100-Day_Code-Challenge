#include <bits/stdc++.h>
using namespace std;

#define FIO       ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a)    ((a).begin()), ((a).end())
#define printarr  (v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v)    for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

using vi   =  vector<int>;
using vvi  =  vector<vector<int>>;
using vll  =  vector<long long>;
using vvll =  vector<vector<long long>>;
using ll   =  long long;
using ld   =  long double;
using ull  =  unsigned long long;
using pii  =  pair<int, int>;
using pll  =  pair<long long, long long>;

void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << a << " ";
    err(++it, args...);
};

void solve()
{
	int n; cin >> n;
	
	string a, b;
	cin >> a >> b;
	
	vi dp(n + 1, 1e9);
	
	// dp[0] = (a[0] == b[0] ? 0 : 1);
	dp[0] = 0;
	
	for(int i = 0; i < n; i++)
	{
		dp[i + 1] = min(dp[i + 1], dp[i] + (a[i] != b[i]));
		
		if (i + 1 < n and a[i] == b[i + 1] and a[i + 1] == b[i])
			dp[i + 2] = min(dp[i + 2], dp[i] + 1);	
	}
	
	cout << dp.back() << "\n";
}

int main()
{
    FIO;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}