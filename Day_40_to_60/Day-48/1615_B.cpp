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
const int MAXN = 200004;
int cnt[MAXN][25] {};

void preprocess(int l, int r)
{
	for(int i = l; i <= r; i++)
	{
		for(int j = 0; j < 25; j++)
			cnt[i][j] += (getBit(i, j) + cnt[i - 1][j]);
	}
}

void solve()
{
	int l, r;
	cin >> l >> r;
	
	int n = r - l + 1;
	int ans = n;
	// printarr(cnt, 0, 7);
	
	for(int i = 0; i < 25; i++)
		ans = min(ans, n - cnt[r][i] + cnt[l - 1][i]);
	
	cout << ans << "\n";
}

int main()
{
    FIO;
    preprocess(1, MAXN - 1);    
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}