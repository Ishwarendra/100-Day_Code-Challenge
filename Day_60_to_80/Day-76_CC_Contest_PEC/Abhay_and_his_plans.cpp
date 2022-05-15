#include<bits/stdc++.h>

int main()
{
	try {
		int n;
		std::cin >> n;

		std::vector<int> a(n);

		for (int i = 0; i < n; ++i)
			std::cin >> a[i];

		if (n == 1)
		{
			try {
				std::cout << a[0] << "\n";
				return 0;
			}
			catch (...)
			{
				return 0;
			}
		}

		std::vector<int> dp(n);

		dp[0] = a[0];
		dp[1] = std::max(a[0], a[1]);

		for (int i = 2; i < n; ++i)
			dp[i] = std::max(dp[i - 1], dp[i - 2] + a[i]);

		std::cout << dp.back() << "\n";

		return 0;
	}
	catch (const std::exception &e)
	{
		return 0;
	}
}