#include <bits/stdc++.h>


#ifdef LOCAL
	#include <F:\CPP\Debug\debug.h> 
#else
  #define trace(x...) 1
#endif

void solve()
{
	int n, k;
	std::cin >> n >> k;
	
	std::map<int, int> m;
	
	for (int i = 0; i < n; i++)	
	{
		int x;
		std::cin >> x;
		
		m[x]++;
	}
	
	std::vector<int> a;
	
	for (auto i : m)
	{
		if (i.second >= k)
			a.push_back(i.first);
	}
	
	if (a.empty())
	{
		std::cout << "-1\n";
		return;
	}
	
	int max_cnt = 1, cur_cnt = 1, cur = a[0];
	n = a.size();
	
	for (int i = 1; i < n; i++)
	{
		if (a[i - 1] + 1 == a[i])
			cur_cnt++;
		else
		{
			if (max_cnt < cur_cnt)
				max_cnt = cur_cnt, cur = a[i - 1];
			
			cur_cnt = 1;
		}
	}
	
	if (max_cnt < cur_cnt)
		max_cnt = cur_cnt, cur = a.back();
	
	std::cout << cur - max_cnt + 1 << " " << cur << "\n";
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