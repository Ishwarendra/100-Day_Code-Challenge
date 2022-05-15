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

// ax + by = g
int diophantine_base_sol(int a, int b, int &x, int &y)
{
	if (b == 0)
	{
		x = 1, y = 0;
		return a;
	}
	
	int tmp_x, tmp_y;
	int g = diophantine_base_sol(b, a % b, tmp_x, tmp_y);
	
	x = tmp_y; 
	y = tmp_x - tmp_y * (a/b);
	
	return g;
}

int a, b, x;

int good(int mid)
{
	// int first = 111 * mid - x * 10;
	// int second = x - 11 * mid;
	int first = 1, second = 9;
	
	
	if (first >= 0 and second >= 0)
		return 0;
	
	else if (first >= 0 and second < 0)
		return 1;
	
	else if (first < 0 and second >= 0)
		return -1;
	
	else
		return -2;
}

void solve()
{
	cin >> x;
	
	// (11*a + 111*b = x)
	diophantine_base_sol(11, 111, a, b);
	
	int left = (10*x + 110)/111, right = x/11;
	
	while(left <= right)
	{
		int mid = (left + right)/2;
		if (good(mid) == 0)
		{
			cout << "YES\n";
			return;
		}
		
		else if (good(mid) == 1)
			left = mid + 1;
		else if (good(mid) == -1)
			right = mid - 1;
		
		else
		{
			cout << "NO\n";
			return;
		}
	}
	
	cout << "NO\n";
}

int32_t main()
{
	FIO;
	int t = 1; cin >> t;
	while(t--)
		solve();
}