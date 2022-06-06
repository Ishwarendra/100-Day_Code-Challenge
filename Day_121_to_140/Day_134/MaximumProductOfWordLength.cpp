#include <bits/stdc++.h>

#define LOCAL 1

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

class Solution {
public:
	int maxProduct(std::vector<std::string>& words)
	{
		int n = words.size();
		std::vector<std::vector<int>> cnt(n, std::vector<int>(26));

		for (int i = 0; i < n; ++i)
		{
			for (auto ch : words[i])
				cnt[i][ch - 'a']++;
		}

		int ans = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				bool ok = true;
				for (int k = 0; k < 26; k++)
					if (cnt[i][k] and cnt[j][k])
					{
						ok = false;
						break;
					}

				if (ok)
					ans = std::max(ans, (int)words[i].size() * (int)words[j].size());
			}
		}

		return ans;
	}
};

int main()
{
	return 0;
}