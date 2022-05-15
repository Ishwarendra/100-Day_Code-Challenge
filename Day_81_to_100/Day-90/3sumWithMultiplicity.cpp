#include <bits/stdc++.h>

class Solution {
	const int mod = 1e9 + 7;
public:
	Solution()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
	}
	int threeSumMulti(std::vector<int>& arr, int target) {
		std::map<int, int> m;
		int n = arr.size();

		int ans = 0;

		for (int j = 0; j < n; ++j)
		{
			for (int k = j + 1; k < n; ++k)
				ans = (ans + m[target - arr[j] - arr[k]]) % mod;

			m[arr[j]]++;
			m[arr[j]] %= mod;
		}

		return ans;
	}
};

int main()
{
	std::vector<int> arr {2, 2, 2};
	int target = 6;

	Solution ans;
	std::cout << ans.threeSumMulti(arr, target);

	return 0;
}