#include <bits/stdc++.h>

char converse(char ch)
{
	return 25 - (ch - 'a') + 'a';
}

void solve()
{
	int n;
	std::string s;
	
	std::cin >> n >> s;
	
	for (int i = 0; i < n; ++i)
	{
		if (s[i] != converse(s[n - i - 1]))
		{
			std::cout << "No\n";
			return;
		}
	}	
	
	std::cout << "Yes\n";
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