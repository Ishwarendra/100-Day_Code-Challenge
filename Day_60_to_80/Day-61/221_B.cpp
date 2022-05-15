#include <bits/stdc++.h>
using namespace std;

#define FIO        ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a)     ((a).begin()), ((a).end())
#define printarr   (v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v)     for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define int        long long
#define fps(x, y)  fixed<<setprecision((y))<<(x)
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

bool common(string &a, string b)
{
	for(int i = 0; i < a.length(); i++)
	{
		for(int j = 0; j < b.length(); j++)
			if (a[i] == b[j])
				return true;
	}
	
	return false;
}

void solve()
{
	int x; cin >> x;
	
	string num = to_string(x);
	int n = num.length();
	
	int ans = 0;
	
	for(int i = 1; i*i <= x; i++)
	{
		if (x % i == 0)
		{
			// cout << i << " ";
			string cur = to_string(i);
			if (common(num, cur))
				ans++;
			
			if (x/i != i)
			{
				// cout << x/i << " ";
				cur = to_string(x/i);
				if (common(num, cur))
					ans++;
			}
			
		}
	}	
	
	
	cout << ans << "\n";
}

int32_t main()
{
    FIO;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}