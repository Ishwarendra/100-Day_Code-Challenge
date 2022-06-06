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
	string largestWordCount(vector<string>& messages, vector<string>& senders)
	{
		std::map<std::string, int> m;
		int n = messages.size();

		for (int i = 0; i < n; ++i)
		{
			int cur_cnt = 1;
			for (char ch : messages[i])
				cur_cnt += ch == ' ';

			m[senders[i]] += cur_cnt;
		}

		int maxi = 0;

		for (auto [f, s] : m)
			maxi = std::max(maxi, s);

		std::string ans;

		for (auto [f, s] : m)
		{
			if (s == maxi)
				ans = std::max(ans, f);
		}

		return ans;
	}
};

int main()
{
	Solution sol;
	int n;
	std::cin >> n;

	std::vector<std::string> s(n), m(n);

	for (int i = 0; i < n; ++i)
		std::cin >> m[i];

	for (int i = 0; i < n; ++i)
		std::cin >> s[i];

	return 0;
}