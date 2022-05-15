#include<bits/stdc++.h>

void solve()
{
	int n; std::cin >> n;
	
	std::vector<int> cnt(3);
	
	for(int i = 0; i < n; i++)
	{
		int x;
		std::cin >> x;
		
		cnt[x % 3]++;
	}
	
	int donate = 0;
	
	for(int i = 0; i < 3; i++)
	{
		if (cnt[i] <= n/3)
			continue;
		
		int &next = cnt[(i + 1) % 3];
		int &nextnext = cnt[(i + 2) % 3];
		
		if (next < n/3)
		{
			int change = std::min(n/3 - next, cnt[i] - n/3);
			next += change;
			cnt[i] -= change;
			
			donate += change;
		}
		
		if (cnt[i] == n/3)
			continue;
		
		if (nextnext < n/3)
		{
			int change = std::min(n/3 - nextnext, cnt[i] - n/3);
			nextnext += change;
			cnt[i] -= change;
			
			donate += 2 * change;
		}
	}
	
	std::cout << donate << "\n";
}

int main()
{
	int t;
	std::cin >> t;
	
	while(t--)
		solve();
	
	return 0;
}	