#include <bits/stdc++.h>
using namespace std;

#define FIO       ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a)    ((a).begin()), ((a).end())
#define printarr  (v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v)    for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define int       long long
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

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

bool good(int mid, vi &a, int k, int pr = false)
{
	int n = a.size();
	int cur_median = a[n/2];
	
	int to_add = 0;
	
	for(int i = (n/2); i < n; i++)
		to_add += max(0LL, mid - a[i]);
	
	if (pr)
		print(to_add, mid, cur_median);
		
	return (to_add <= k);
}

void solve()
{
	int n, k;
	cin >> n >> k;
	
	vi a(n);
	
	for(auto &x: a)
		cin >> x;
	
	sort(all(a));
	
	int median = a[n/2];
	
	int low = median, high = 2e9;
	
	while(low <= high)
	{
		int mid = low + (high - low)/2;
		
		if (good(mid, a, k))
		{
			// good(mid, a, k, true);
			median = mid, low = mid + 1;
		}
		else
			high = mid - 1;
	}
	
	cout << median << "\n";
}

int32_t main()
{
    FIO;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}