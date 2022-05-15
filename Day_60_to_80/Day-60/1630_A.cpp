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

/*
n-1, n-2
n - 3 1
0 2

2 n - 3
1 n - 2
0 n - 1

0 2 => 0
6 7 => 6
1 5 => 1
3 4 => 0
..
*/

void solve()
{
	int n, k; cin >> n >> k;
	
	vector<pii> pairs;
	
	for(int i = 0; i < n/2; i++)
		pairs.push_back({i, n - 1 - i});
	
	if (k == n - 1 and n == 4)
		cout << "-1\n";
	else if (k == n - 1)
	{
		for(int i = 3; i < n/2; i++)
			print(pairs[i].first, pairs[i].second);
		
		print("0 2");
		print("1", n - 3);
		print(n - 2, n - 1);
	}
	else
	{
		for(int i = 0; i < n/2; i++)
		{
			if (i == k)
				swap(pairs[i].second, pairs[0].second);
			else if (n - 1 - i == k)
				swap(pairs[i].first, pairs[0].second);
		}
		
		for(pii p : pairs)
			print(p.first, p.second);
	}
}

int32_t main()
{
    FIO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}