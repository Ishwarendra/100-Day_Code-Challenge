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
public:
	bool digitCount(string num)
	{
		std::map<int, int> m;
		int n = num.size();

		for (int i = 0; i < n; i++)
			m[i] = num[i] - '0';

		trace(m)

		for (int i = 0; i < n; i++)
		{
			if (std::count(num.begin(), num.end(), (char)(i + '0')) != m[i])
				return false;
		}


		return true;
	}
};

int main()
{
	Solution sol;
	sol.digitCount("030");
	return 0;
}