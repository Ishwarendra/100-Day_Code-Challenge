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
    int findMaxForm(vector<string>& strs, int m, int n) 
    {   
    	std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));
    	
    	for (int i = 0; i < strs.size(); i++)
    	{
			int one = std::count(strs[i].begin(), strs[i].end(), '1');
			int zero = strs[i].length() - one;
			
    		for (int j = 0; j <= m - zero; j++)
    		{
    			for (int k = 0; k <= n - one; k++)
    			{
    				dp[j][k] = std::max(dp[j][k], dp[j + zero][k + one] + 1);
    			}
    		}
    	}
    	
    	return dp[0][0];
    }
};

int main()
{
	std::vector<std::string> a {"10","0001","111001","1","0"};
	int m = 5, n = 3;
	
	Solution sol;
	sol.findMaxForm(a, m, n);
	
	return 0; 
}    