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
	static constexpr int inf = 1e9;
public:
    int coinChange(vector<int>& coins, int amount) 
    {
    	int n = coins.size();
    	std::vector<int> dp(amount + 1, inf);
    	
    	dp[0] = 0;
    	
    	for (int coin : coins)
    	{
    		if (coin <= amount)
	    		dp[coin] = 1; 
    	}
    	
    	for (int i = 1; i <= amount; i++)
    	{
    		for (int coin : coins)
    		{
    			if (i + (coin - amount) <= 0) // Overflow :checkmark:
    				dp[i + coin] = std::min(dp[i + coin], dp[i] + 1);
    		}
    	}
    	
    	return dp[amount] == inf ? -1 : dp[amount];
    }
};

int main()
{
	
	return 0; 
}    