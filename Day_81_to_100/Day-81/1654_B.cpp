#include <bits/stdc++.h>

void solve()
{
	std::string s;
	std::cin >> s;
	
	std::vector<int> freq(26);
	
	for (char ch : s)
		freq[ch - 'a']++;
		
	std::string ans;
	
	int start = s.length();
	
	for (int i = 0; i < s.length(); i++)
	{
		char ch = s[i];
		
		if (freq[ch - 'a'] > 1)
		{
			freq[ch - 'a']--;
			continue;
		}
		else if (freq[ch - 'a'] == 1)
		{
			start = i;
			break;
		}
	}	
		
	for (int i = start; i < s.length(); i++)
		ans += s[i];
	
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