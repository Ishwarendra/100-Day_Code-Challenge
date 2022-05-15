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
	int n; cin >> n;
	
	vi a(n);
	
	for(auto &_ : a)
		cin >> _;
	
	if (n == 1 or n == 2)
	{
		cout << "0\n";
		return;
	}
	
	set<int> pos_diff, neg_diff;
	
	for(int i = 1; i < n; i++)
	{
		int diff = a[i] - a[i - 1];
		
		if (diff > 0)
			pos_diff.insert(diff);
		else
			neg_diff.insert(diff);
	}
	
	// If more than one of positive diff or negative difference
	if (pos_diff.size() > 1 or neg_diff.size() > 1)
	{
		cout << "-1\n";
		return;
	}
	
	// No pos or no neg diff .. inf m 
	if (pos_diff.empty() or neg_diff.empty())
	{
		cout << "0\n";
		return; 
	}
	
	// pos and neg diff both 1
	int pos = *pos_diff.begin();
	int neg = *neg_diff.begin();
	
	int m = pos - neg;
	int c = pos;
	
	if (c >= m)
	{
		cout << "-1\n";
		return;
	}	
	
	vi generate(n);
	generate[0] = a[0] % m;
	
	for(int i = 1; i < n; i++)
		generate[i] = (generate[i - 1] + c) % m;
	
	for(int i = 0; i < n; i++)
	{
		if (generate[i] != a[i])
		{
			cout << "-1\n";
			return;
		}
	}
	
	cout << m << " " << c << "\n";
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