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
	std::vector<int> dp;
	int f(int x)
	{
		if (dp[x] != -1)
			return dp[x];
		
		if (x % 2)
			dp[x] = f(x - 1) + 1;
		else
			dp[x] = f(x / 2) + 1;
		
		return dp[x];
	}
public:
    int numberOfSteps(int num) 
    {
    	dp.resize(num + 1, -1);
    	dp[0] = 0, dp[1] = 1;
    	
    	return f(num);
    }
};

int main()
{
	return 0; 
}    