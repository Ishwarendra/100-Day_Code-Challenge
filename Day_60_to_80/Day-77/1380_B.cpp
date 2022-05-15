#include <bits/stdc++.h>

std::map<char, char> par;

void solve()
{
	std::string s;
	std::cin >> s;
	
	std::map<char, int> freq;
	
	for(int i = 0; i < s.length(); i++)
		freq[s[i]]++;
	
	std::vector<char> elems {'R', 'P', 'S'};
	
	int best = 0;
	
	for(int i = 1; i < 3; i++)
		if (freq[elems[i]] > freq[elems[best]])
			best = i;
		
	for(int i = 0; i < s.length(); i++)
		std::cout << par[elems[best]];
	
	std::cout << "\n";
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	par['R'] = 'P', par['P'] = 'S', par['S'] = 'R';
	
	int t = 1;
	std::cin >> t;
	
	while(t--)
		solve();
	
	return 0;
}