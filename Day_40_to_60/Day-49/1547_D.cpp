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

vi oneBitPos(int x)
{
	vi ans(31);
	for(int i = 0; i < 31; i++)
		ans[i] = getBit(x, i);
	
	return ans;
}

void solve()
{
	int n; cin >> n;
	vi x(n), y(n);
	
	for(int i = 0; i < n; i++)
		cin >> x[i];	
	
	vi prev = oneBitPos(x[0]);
	
	for(int i = 1; i < n; i++)
	{
		vi cur = oneBitPos(x[i]);
		
		int cur_num = 0;
		
		for(int i = 0; i < 31; i++)
		{
			if (prev[i] == 1 and cur[i] == 0)
				cur_num = setBit(cur_num, i);
		}
		
		y[i] = cur_num;
		
		x[i] ^= y[i];
		
		prev = oneBitPos(x[i]);
	}
	
	log(y);
}

int main()
{
    FIO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}