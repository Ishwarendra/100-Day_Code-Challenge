#include <bits/stdc++.h>
using namespace std;

#define FIO        ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a)     ((a).begin()), ((a).end())
#define log(v)     for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define int        long long
#define fps(x, y)  fixed<<setprecision((y))<<(x)
#define printarr(v, start, end) for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define print(args...) {string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

using ll       =    long long;
using vi       =    vector<int>;
using vvi      =    vector<vector<int>>;
using ld       =    long double;
using pii      =    pair<int, int>;
using mii      =    map<int, int>;
using umii     =    unordered_map<int, int>;
using maxheap  =    priority_queue<int>;
using minheap  =    priority_queue<int, vector<int>, greater<int>>;

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

	vi a(n + 1);
	vvi pos(n + 1);

	vector<bool> vis(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		vis[a[i]] = true;
		pos[a[i]].push_back(i);
	}

	set<int> in_hand;
	int unsatis = 0;

	for (int i = 1; i <= n; i++)
	{
		if (not vis[i])
			in_hand.insert(i);
	}

	for (int i = 1; i <= n; i++)
	{
		int cur_size = pos[i].size();

		if (cur_size <= 1)
			continue;

		for (int j = 0; j < cur_size - 1; j++)
		{
			auto cur = in_hand.begin();
			
			if (*cur == pos[i][j] and *(--in_hand.end()) == pos[i][j])
			{
				a[pos[i][cur_size - 1]] = *cur;
				in_hand.erase(*cur);
			}
			
			else if (*cur == pos[i][j])
			{
				cur = --in_hand.end();
				a[pos[i][j]] = *cur;
				in_hand.erase(*cur);	
			}
			else 
			{
				a[pos[i][j]] = *cur;
				in_hand.erase(*cur);
			}
			
			
			unsatis++;
		}
	}

	for (int i = 1; i <= n; i++)
		assert(a[i] != i);
	
	print(n - unsatis);
	printarr(a, 1, a.size());
}

int32_t main()
{
	FIO;
	int t = 1;
	cin >> t;
	while (t--)
		solve();

	return 0;
}