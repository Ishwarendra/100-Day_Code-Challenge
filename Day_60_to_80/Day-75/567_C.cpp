#include<bits/stdc++.h>

#define int long long

int32_t main()
{
	int n, k;
	std::cin >> n >> k;

	std::vector<int> a(n);
	std::map<int, int> behind, after;

	for (int i = 0; i < n; ++i)
	{
		std::cin >> a[i];
		after[a[i]]++;
	}

	int ans = 0;

	for (int i = 0; i < n; ++i)
	{
		after[a[i]]--;
		
		if (a[i] % k == 0)
		{
			int cur = a[i];
			int x = behind[a[i] / k];

			if (x)
			{
				int y = after[a[i] * k];
				ans += x * y;
			}
		}
		
		behind[a[i]]++;
	}

	std::cout << ans << "\n";

	return 0;
}