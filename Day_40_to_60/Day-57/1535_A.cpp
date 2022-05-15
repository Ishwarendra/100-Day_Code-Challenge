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
	vi s(4);
	int maxi = 0, secondmaxi = -1;
	for(int i = 0; i < 4; i++)
		cin >> s[i];

	for(int i = 1; i < 4; i++)
	{
		if (s[i] > s[maxi])
			secondmaxi = maxi, maxi = i;
		else if (secondmaxi == -1)
			secondmaxi = i;
		else if (s[i] > s[secondmaxi])
			secondmaxi = i;
	}
	// print(maxi, secondmaxi)
	if ((maxi == 0 or maxi == 1) and (secondmaxi == 2 or secondmaxi == 3))
	{
		cout << "YES\n";
		return;
	}
	
	swap(maxi, secondmaxi);
	if ((maxi == 0 or maxi == 1) and (secondmaxi == 2 or secondmaxi == 3))
		cout << "YES\n";
	else
		cout << "NO\n";
}

int main()
{
    FIO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}