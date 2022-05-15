#include <bits/stdc++.h>
using namespace std;

#define FIO       ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a)    ((a).begin()), ((a).end())
#define printarr  (v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v)    for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

using vi   =  vector<int>;
using vvi  =  vector<vector<int>>;
using vll  =  vector<long long>;
using vvll =  vector<vector<long long>>;
using ll   =  long long;
using ld   =  long double;
using ull  =  unsigned long long;
using pii  =  pair<int, int>;
using pll  =  pair<long long, long long>;

void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << a << " ";
    err(++it, args...);
};

// 1 to 9, 11, 22, ..., 99, 111, 222, ..., 999, 1111 .... 9999
// 9*9

void solve()
{
	string s; cin >> s;
	
	int n = s.length();
	
	int ans = 9*(n - 1);
	
	for(int i = 0; i < 9; i++)
	{
		string tmp;
		for(int j = 0; j < n; j++)
			tmp += (char)(i + '1');
		
		if (tmp <= s)
			ans++;
	}	
		
	cout << ans << "\n";
}

int main()
{
    FIO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}