#include<bits/stdc++.h>

std::map<char, char> m;
std::set<char> open_braces {'(', '{', '[', '<'};

int main()
{
	m['('] = ')', m['<'] = '>', m['{'] = '}', m ['['] = ']';
	
	std::string s;
	std::cin >> s;
	
	int n = s.length();
	
	std::stack<char> st;
	int open = 0, close = 0, ans = 0;
	
	for(int i = 0; i < n; i++)
	{
		char cur = s[i];
		
		if (open_braces.count(cur))
		{
			st.emplace(cur);
			open++;
		}		
		else
		{
			close++;
			if (st.empty())
			{
				std::cout << "Impossible\n";
				return 0;
			}
				
			int top = st.top();
			st.pop();
			
			if (cur != m[top])
				ans++;
		}
		
		if (close > open)
		{
			std::cout << "Impossible\n";
			return 0;
		}
	}
	
	if (st.empty())
		std::cout << ans << "\n";
	else
		std::cout << "Impossible\n";
	
	return 0;
}