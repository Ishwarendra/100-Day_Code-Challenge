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

void err(istream_iterator<string> it) {};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
	cout << a << " ";
	err(++it, args...);
};

void solve()
{
	int n; cin >> n;

	int start_num = ((n + 1) / 2) * n + 1;

	if (n == 1)
		cout << "1\n";
	else if (n == 2)
		cout << "-1\n";
	else if (n == 3)
		cout << "2 9 7\n4 6 3\n1 8 5\n";
	else
	{
		int cnt = 0, cur = 1;
		for (int i = 0; i < n; i++)
		{
			bool start = false;
			for(int j = 0; j < n; j++)
			{
				if (start)
					cout << start_num++ << " ";
				else
					cout << cur++ << " ";
				
				start ^= 1;
			}
			cout << "\n";
		}
	}
}

int main()
{
	FIO;
	int t = 1;
	cin >> t;
	while (t--)
		solve();
}