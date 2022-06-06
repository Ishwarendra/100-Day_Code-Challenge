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
	int missingNumber(vector<int>& nums) {
		int xor1 = 0, xor2 = 0;
		int n = nums.size();
		for (int i = 0; i < n; i++)
		{
			xor1 ^= nums[i], xor2 ^= i;
		}

		xor2 ^= n;

		return xor1 ^ xor2;
	}
};

int main()
{
	return 0;
}