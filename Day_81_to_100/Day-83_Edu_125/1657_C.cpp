#include <bits/stdc++.h>

void solve()
{
	int n;
	std::cin >> n;
	
	std::string s;
	std::cin >> s;
	
	if (n == 1)
	{
		std::cout << "0 1\n";
		return;
	}
	
	int op = 0, i;
	
	for (i = 1; i < n;)
	{
		if (s[i - 1] == '(')
			op++, i += 2;
		else 
		{
			if (s[i] == ')')
				op++, i += 2;
			else
			{
				int counter = i;
				while (counter < n and s[counter] == '(')
					counter++;
				
				if (counter < n)
					op++, i = counter + 2;
				else
					break;
			}
		}
	}
	
	std::cout << op << " " << n - i + 1 << "\n";
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