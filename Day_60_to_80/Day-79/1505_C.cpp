#include<bits/stdc++.h>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::string s;
	std::cin >> s;
	
	int n = s.length();
	
	if (n == 1 or n == 2)
	{
		std::cout << "YES\n";
		return 0;
	}
	
	for (int i = 2; i < n; i++)
	{
		int prev = s[i - 2] - 'A';
		int cur = s[i - 1] - 'A';
		int next = s[i] - 'A';
		
		if (next != (prev + cur) % 26)
		{
			std::cout << "NO\n";
			return 0;
		}	
		
	}	
	
	std::cout << "YES\n";
	
	return 0;
}