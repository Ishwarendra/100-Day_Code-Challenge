#include<bits/stdc++.h>

void print(int x, int y, int p, int q, std::string &s)
{
	int id = 0;

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < p; j++)
			std::cout << s[id++];

		std::cout << "\n";
	}

	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < q; j++)
			std::cout << s[id++];

		std::cout << "\n";
	}
}

int main()
{
	int n, p, q;
	std::cin >> n >> p >> q;

	std::string s;
	std::cin >> s;

	// px + qy = n
	int x, y;

	for (x = 0; x <= n; x++)
	{
		for (y = 0; y <= n; y++)
		{
			if (p * x + q * y == n)
			{
				std::cout << x + y << "\n";
				print(x, y, p, q, s);
				return 0;
			}
		}
	}

	std::cout << "-1\n";
	
	return 0;
}