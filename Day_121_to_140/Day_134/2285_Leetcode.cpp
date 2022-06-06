#include <bits/stdc++.h>
using namespace std;

#define LOCAL 1

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

using i64 = long long;

class Solution {
public:
	i64 maximumImportance(int n, vector<vector<int>>& roads)
	{
		std::vector<int> deg(n);

		for (auto road : roads)
		{
			int a = road[0], b = road[1];
			deg[a]++, deg[b]++;
		}

		std::sort(deg.begin(), deg.end(), std::greater());

		i64 ans = 0;
		int cur_num = n;

		for (int i : deg)
		{
			ans += 1LL * cur_num * i;
			cur_num--;
		}

		return ans;
	}
};

int main()
{
	return 0;
}