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


void solve()
{
	ll n; cin >> n;
	ll sum = 0LL;
	
	vll a(n + 1);	
	
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	
	if (sum % n)
	{
		cout << "-1\n";
		return;
	}
	
	vector<vi> operations;
	
	for(int i = 2; i <= n; i++)
	{
		ll x = (i - (a[i] % i)) % i;
		
		// Make a[i]/i an integer	
		vi cur {1, i, x};
		if (x != 0)
			operations.push_back(cur);
		
		// Add it to a
		cur = {i, 1, (a[i] + x)/i};
		operations.push_back(cur);
	}
	
	for(int i = 2; i <= n; i++)
	{
		vi cur {1, i, sum/n};
		operations.push_back(cur);
	}
	
	print(operations.size());	
	for(auto cur : operations)
		print(cur[0], cur[1], cur[2]);
}

int main()
{
    FIO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}