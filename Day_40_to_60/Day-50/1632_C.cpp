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

int getBit(int x, int pos)
{
	return (x & (1 << pos)) != 0;
}

int setBit(int x, int pos)
{
	return (x | (1 << pos));
}

void solve()
{
	int a, b;
	cin >> a >> b;
	
	int ans = b - a;
	
	for(int j = a; j < b; j++)
	{
		int a_new = j;
		int b_new = 0;
		
		for(int i = 22; i >= 0; i--)
		{
			if (getBit(b, i))
				b_new = setBit(b_new, i);
			else if (getBit(a_new, i))
			{
				b_new = setBit(b_new, i);
				break;
			}
		}
		ans = min(ans, a_new + (b_new|a_new) + 1 - a - b);
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