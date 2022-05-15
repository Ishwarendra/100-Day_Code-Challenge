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

const ll mod = 998244353;

void solve()
{
	int n; string s;
	cin >> n >> s;
	
	if (n == 2)
	{
		cout << "3\n";
		return;
	}
	
	int i = 1, j = n - 2;
	
	while(i < n and s[i] == s[i - 1])
		i++;
	
	while(j >= 0 and s[j] == s[j + 1])
		j--;
	
	ll left = i, right = n - j - 1;
	// print(left, right)
	if (s[i - 1] == s[j + 1])
		cout << ((left + 1)*(right + 1))%mod << "\n";
	else
	{
		cout << (left + right + 1) % mod << "\n";
	}
}

int main()
{
    FIO;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
}