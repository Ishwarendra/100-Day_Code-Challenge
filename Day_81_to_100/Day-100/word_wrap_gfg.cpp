#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

class Solution {
	int sq(int k)
	{
		return k * k;
	}
	
	
	void print(vector<vector<int>> &a)
	{
		for (int i = 0; i < a.size(); i++)
		{
			for (int j = 0; j < a[i].size(); ++j)
				cout << a[i][j] << " ";
			cout << "\n";
		}
	} 
	
	void print(vector<int> &a)
	{
	    for (int i : a)
	    cout << i << " "; cout << "\n";
	}
public:
    int solveWordWrap(vector<int> &nums, int k) 
    { 
  		int n = nums.size();
  		
  		vector<vector<int>> space(n + 1, vector<int>(n + 1));
  		vector<vector<int>> lc(n + 1, vector<int>(n + 1));
  		vector<int> cost(n + 1, inf);
  		
  		for (int i = 1; i <= n; i++)
  		{
  			space[i][i] = k - nums[i - 1];
  			for (int j = i + 1; j <= n; j++)
  				space[i][j] = space[i][j - 1] - nums[j - 1] - 1; 
  		}
  		
  		for (int i = 0; i < n; i++)
  		{
  			for (int j = i; j < n; j++)
  			{
  				if (space[i][j] < 0)
  					lc[i][j] = inf;
  				else if (j == n)
  					lc[i][j] = 0;
  				else
  					lc[i][j] = sq(space[i][j]);
  			}
  		}
  		
  		cost[0] = 0;
  		
  		for (int i = 1; i <= n; i++)
  		{
  			for (int j = 1; j <= i; j++)
  			{
  				if (cost[i - 1] != inf and lc[j][i] != inf)
	  				cost[i] = min(cost[i], cost[i - 1] + lc[j][i]);
  			}
  		}
 		print(cost);
 		
 		if (cost[n] == 0)
 			cost[n] = cost[n - 1];
 		 		
  		return cost.back();
    } 
};

int main()
{
	Solution a;
	vector<int> nums {10, 6, 5, 3, 1, 10, 8, 2};
	int k = 12;
	cout << a.solveWordWrap(nums, k);
	return 0; 
}    