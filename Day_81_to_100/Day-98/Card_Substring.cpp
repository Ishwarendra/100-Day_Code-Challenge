#include<bits/stdc++.h>

using i64 = long long;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, m;
	std::cin >> n >> m;
	
	std::string s;
	std::cin >> s;
	
	std::map<char, int> cnt1, cnt2;
		
	for (int i = 0; i < m; i++)
	{
		char ch; std::cin >> ch;
		cnt2[ch]++;
	}
	
	int i = 0, j = 0;
	i64 ans = 0;
	
	while (j < n)
	{
		cnt1[s[j]]++;
		
		while (cnt1[s[j]] > cnt2[s[j]])
		{
			cnt1[s[i]]--;
			i++;
		}
		
		ans += (j - i + 1);
		j++;
	}
	
	std::cout << ans << "\n";
	
	return 0;
}