#include<bits/stdc++.h>

using i64 = long long;

void ready_map(std::map<std::string, char> &m)
{
	m["zero"] = '0';
	m["one"] = '1';
	m["two"] = '2';
	m["three"] = '3';
	m["four"] = '4';
	m["five"] = '5';
	m["six"] = '6';
	m["seven"] = '7';
	m["eight"] = '8';
	m["nine"] = '9';
}

std::string getPhoneNumber(std::string &s)
{
	std::map<std::string, char> m;
	ready_map(m);
	
	std::string cur;
	
	int times = 1;
	
	std::string ans;
	
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ')
		{
			if (cur == "double")
				times = 2;
			else if (cur == "triple")
				times = 3;
			else
			{
				for (int i = 0; i < times; i++)	
					ans += m[cur];
				
				times = 1;
			}
			
			cur.clear();
		}
		else
			cur += s[i];
	}
	
	for (int i = 0; i < times; i++)
		ans += m[cur];
	
	return ans;
}

int main()
{
	std::string s;
	std::getline(std::cin, s, '\n');
	
	std::string ans = getPhoneNumber(s);
	
	std::cout << ans << "\n";
	
	return 0;
}