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

vi *adj;
bool possible = true;

void dfs(int cur, int par, int c, vector<int> &col)
{
	col[cur] = c;
	
	for(int nb : adj[cur]){
		if (nb == par)
			continue;
		if (col[nb] == 0) // neighbour not discovered yet
			dfs(nb, cur, 3 - c, col);
		else if (col[nb] == c) // already processed so backedge it is 
			possible = false;	
	}
}

void solve()
{
	int n, m;
	cin >> n >> m;
	adj = new vi[n + 1];
	vi start(m), end(m);
	for(int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		start[i] = u, end[i] = v;
		
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	vector<int> col(n + 1);
	dfs(1, 0, 1, col); // 1 - red 2 - black (edge from red to black)

	if (possible){
		cout << "YES\n";
		for(int i = 1; i <= m; i++)
		{
			if (col[start[i - 1]] == 1 and col[end[i - 1]] == 2)
				cout << "0";
			else
				cout << "1";
		}
	}
	else
		cout << "NO\n";
}

int main()
{
    FIO;
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}