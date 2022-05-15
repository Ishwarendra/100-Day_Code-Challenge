#include <bits/stdc++.h>
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

void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << a << " ";
    err(++it, args...);
};

int min_team_member(int x, int id, const vi &a)
{
	int left = 0, right = a.size();
	int ans = 1e6;
	
	while(left <= right)
	{
		int mid = (left + right)/2;
				
		if (mid * a[id] >= x)
			ans = mid, right = mid - 1; 
		else
			left = mid + 1;
	}
	
	return ans;
}

vi min_member_forall(int x, vi &a)
{
	int n = a.size();
	vi b(n);
	
	for(int i = 0; i < n; i++)
		b[i] = min_team_member(x, i, a);
		
	return b;
}


void solve()
{
	int n, x; cin >> n >> x;
	
	vi a(n);
	
	for(auto &_ : a)
		cin >> _;
	
	sort(all(a), greater<int>());
	
	vi b = min_member_forall(x, a);
	
	vi dp(n + 1);
	
	for(int i = 1; i <= n; i++)
	{
		dp[i] = dp[i - 1];
		
		if (i - b[i - 1] >= 0)
			dp[i] = max(dp[i], 1 + dp[i - b[i - 1]]);
		
	}
	
	cout << dp[n] << "\n";
}

int32_t main()
{
	FIO;
	int t = 1; 
	cin >> t;
	while(t--)
		solve();
	
	return 0;
}