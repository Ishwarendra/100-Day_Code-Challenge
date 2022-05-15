#include <bits/stdc++.h>

void solve()
{
	int n;
	std::cin >> n;
	
	std::vector<int> a(n);
	
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
			
	int height = 1;
	bool unwatered = true;
	
	if (a[0] == 1)
	{
		height++;
		unwatered = false;
	}
	
	for (int i = 1; i < n; i++)
	{
		if (a[i] == 1)
		{
			if (unwatered)
				height++;
			else
				height += 5;
			
			unwatered = false;
		}
		else
		{
			if (unwatered)
			{
				std::cout << "-1\n";
				return;
			}
			else
				unwatered = true;
		}
	}	
	
	std::cout << height << "\n";
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