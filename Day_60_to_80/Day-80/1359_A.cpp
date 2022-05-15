#include <bits/stdc++.h>

void solve()
{
	int n, m, k;
	std::cin >> n >> m >> k;
	
	int max_joker = std::min(n / k, m);
	
	m -= max_joker;
	
	int min_joker = m / (k - 1);
	
	if (min_joker * (k - 1) < m)
		min_joker++;
	
	std::cout << max_joker - min_joker << "\n";
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;
	
	while(t--)
		solve();
	
	return 0;
}