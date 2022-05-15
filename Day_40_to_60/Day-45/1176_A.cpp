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

bool possible(ll n)
{
	while(n % 2 == 0)
		n /= 2;
	while(n % 3 == 0)
		n /= 3;
	while(n % 5 == 0)
		n /= 5;
	
	if (n != 1)
		return false;
	return true;
}

void solve()
{
	ll n; cin >> n;
	ll steps = 0LL;
	if (not possible(n))
	{
		cout << "-1\n";
	}
	else
	{
		while(n % 2 == 0)
			n /= 2, steps++;
		while(n % 3 == 0)
			n /= 3, steps += 2;
		while(n % 5 == 0)
			n /= 5, steps += 3;
		
		cout << steps << "\n";
	}
}

int main()
{
    FIO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}