#include<bits/stdc++.h>

#define int long long

std::vector<int> *adj;
std::vector<int> cnt(2);

template<class T>
T power(T a, int b, int mod = 998244353) {
	T res = 1;
	for (; b; b /= 2, a = (a * a) % mod) {
		if (b % 2) {
			res = (res % mod) * (a % mod) % mod;
		}
	}
	return res % mod;
}

void dfs(int cur, std::vector<int> &color, int col, int &bipartite)
{
	color[cur] = col;
	cnt[col]++;

	for (int nb : adj[cur])
	{
		if (color[nb] == -1)
			dfs(nb, color, 1 - col, bipartite);
		else if (color[nb] == color[cur])
			bipartite = 0;
	}
}

void solve()
{
	constexpr int mod = 998244353;

	int n, m;
	std::cin >> n >> m;

	adj = new std::vector<int>[n + 1];

	while (m--)
	{
		int u, v;
		std::cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	std::vector<int> color(n + 1, -1);

	int bipartite = 1, ans = 1;

	for (int i = 1; i <= n; i++)
	{
		int cur = 0;

		if (color[i] == -1)
		{
			std::fill(cnt.begin(), cnt.end(), 0);
			dfs(i, color, 0, bipartite);
		
			cur += power(2LL, cnt[0]);
			cur += power(2LL, cnt[1]);

			cur %= mod;

			ans = (ans % mod) * (cur % mod) % mod;

			if (not bipartite)
			{
				ans = 0;
				break;
			}
		}
	}

	std::cout << ans << "\n";
}

int32_t main()
{
	int t;
	std::cin >> t;

	while (t--)
		solve();

	return 0;
}