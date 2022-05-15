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

void solve()
{
	int n, q, k;
	cin >> n >> q >> k;
	
	vi a(n + 2);
	
	a[0] = 1;
	a[n + 1] = k;
	
	for(int i = 1; i <= n; i++)	
		cin >> a[i];
	
	vi startbehind(n + 2), endafter(n + 2), 
	   midbehind(n + 2), midafter(n + 2);
		
	for(int i = 1; i <= n; i++)
	{
		startbehind[i] = a[i] - 1;
		endafter[i] = k - a[i];
		
		midbehind[i] = a[i] - a[i - 1] - 1;
		midafter[i] = a[i + 1] - a[i] - 1;
	}
	
	vi mid(n + 1);
	
	mid[1] = midbehind[1] + midafter[1];
	for(int i = 2; i <= n; i++)
		mid[i] = mid[i - 1] + midafter[i] + midbehind[i];
		
	while(q--)
	{
		int l, r; cin >> l >> r;
		
		// start[l] + mida[l] + mid(a+b)[l + 1] ... mid(a + b)[r - 1] + end[r] + midb[r]
		int ans = 0;
		
		if (l == r)
			ans += startbehind[l] + endafter[l];
		else
			ans += startbehind[l] + midafter[l] + endafter[r] + midbehind[r];
		
		
		if (r - l >= 2)
			ans += mid[r - 1] - mid[l];
		
		cout << ans << "\n";
	}
}

int32_t main()
{
	FIO;
	int t = 1; 
	// cin >> t;
	while(t--)
		solve();
	
	return 0;
}