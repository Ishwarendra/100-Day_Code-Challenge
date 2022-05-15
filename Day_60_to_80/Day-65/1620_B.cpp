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
	int w, h;
	cin >> w >> h;	
		
	// order -> horid, horiu, vertil, vertir; 
	vector<pii> x(2), y(2);
	
	for(int c = 0; c < 2; c++)
	{
		int k; cin >> k;
		
		for(int i = 0; i < k; i++)
		{
			int tmp; cin >> tmp;
			if (i == 0)
				x[c].first = tmp;
			if (i == k - 1)
				x[c].second = tmp;
		}
	}
	
	if (x[1].second - x[1].first > x[0].second - x[0].first)
		swap(x[0], x[1]);
	
	for(int c = 0; c < 2; c++)
	{
		int k; cin >> k;
		
		for(int i = 0; i < k; i++)
		{
			int tmp; cin >> tmp;
			if (i == 0)
				y[c].first = tmp;
			if (i == k - 1)
				y[c].second = tmp;
		}
	}
	
	if (y[1].second - y[1].first > y[0].second - y[0].first)
		swap(y[0], y[1]);
	
	int area1 = (h * (x[0].second - x[0].first));	
	int area2 = (w * (y[0].second - y[0].first));
	
	print(max(area1, area2));
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