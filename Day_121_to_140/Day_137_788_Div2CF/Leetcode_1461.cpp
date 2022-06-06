#include <bits/stdc++.h>
using namespace std;

#define LOCAL 1

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

class Solution {
	int getBit(int x, int pos)
	{
		return (x >> pos) & 1;
	}

	int setBit(int x, int pos)
	{
		return x | (1 << pos);
	}

	int clearBit(int x, int pos)
	{
		return (x & ((1 << pos) - 1));
	}
public:
	bool hasAllCodes(string s, int k)
	{
		int n = s.size();
		std::vector<int> vis(1 << k);

		int cur = 0;
		int pos = 0;

		for (int i = 0; i < n; i++)
		{
			if (i < k)
			{
				if (s[i] == '1')
					cur = setBit(cur, k - i - 1);

				if (i == k - 1)
				{
					// std::cerr << i << ": " << cur << " \n";
					vis[cur] = 1;
				}
			}
			else
			{
				cur = clearBit(cur, k - 1);
				cur <<= 1;

				if (s[i] == '1')
					cur = setBit(cur, 0);
				
				// std::cerr << i << ": " << cur << "\n";
				vis[cur] = 1;
			}
		}

		for (int i = 0; i < vis.size(); i++)
			if (!vis[i])
				return false;

		return true;
	}
};

int main()
{
	int t;
	std::cin >> t;
	
	while (t--)
	{
		Solution sol;
		
		int k;
		std::string s; std::cin >> s >> k;
		std::cout << std::boolalpha << sol.hasAllCodes(s, k) << "\n"; 
	}
	
	return 0;
}