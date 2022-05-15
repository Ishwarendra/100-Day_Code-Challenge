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

vector<pii> c(4);

int manhattan(int x, int y, pii corner)
{
	return abs(x - corner.first) + abs(y - corner.second);
}

void solve()
{
	int n, m; cin >> n >> m;
	
	c[0].first = 0, c[0].second = 0;
	c[1].first = 0, c[1].second = m - 1;
	c[2].first = n - 1, c[2].second = 0;
	c[3].first = n - 1, c[3].second = m - 1;
	
	vi distance(n*m);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			int cur_dist = 0;
			for(int k = 0; k < 4; k++)
			{
				cur_dist = max(cur_dist, manhattan(i, j, c[k]));
			}
			
			distance[i*m + j] = cur_dist;
		}
	}
	
	sort(all(distance));
	
	for(int i : distance)
		cout << i << " ";
	cout << "\n";
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