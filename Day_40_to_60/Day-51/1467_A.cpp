#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
#define printarr(v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v) for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<long long>;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << a << " ";
    err(++it, args...);
};

// 0 1 2

// 0 0 0 0 0
// 1 1 0 1 1 
// 2 1 0 1 2

// "9 8 7" 6 7 8 9 wrong
// "9 8 9" also possible 

void solve()
{
	int n; cin >> n;
	
	
	int i = 0, cnt = 9;
	
	while(i < min(n, 3))
	{
		cout << cnt;
		i++;
		cnt = 17 - cnt;
	}
	
	cnt = 9;
	cnt = (cnt + 1) % 10;
	
	while(i < n)
	{
		cout << cnt;
		cnt = (cnt + 1) % 10;
		i++;
	}
	
	cout << "\n";
}

int main()
{
    FIO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}