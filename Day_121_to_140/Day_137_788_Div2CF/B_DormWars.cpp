#include <bits/stdc++.h>

#ifdef LOCAL
	#include <F:\CPP\Debug\debug.h> 
#else
	#define trace(x...) 1;
	#define print(x...) 1;
#endif

void solve()
{
	int n;
	std::cin >> n;
	
	std::string s;
	std::cin >> s;
	
	std::set<char> special;
	int k;
	std::cin >> k;
	
	for (int i = 0; i < k; ++i)	
	{
		char ch;
		std::cin >> ch;
		
		special.emplace(ch);
	}
	
	std::vector<std::string> a;
	
	for (int i = 0; i < n;)
	{
		std::string temp;
		while (i < n and special.find(s[i]) == special.end())
			temp += s[i], i++;
		
		if (i < n and special.find(s[i]) != special.end())
			a.push_back(temp);
		
		i++;
	}
	
	if (a.empty())
	{
		std::cout << "0\n";
		return;
	}
	
	int ans = a[0].size();
	
	for (int i = 1; i < a.size(); i++)
		ans = std::max(ans, (int) a[i].size() + 1);
	
	std::cout << ans << "\n";
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