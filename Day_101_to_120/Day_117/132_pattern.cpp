#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) 
    {
    	int n = nums.size();
    	
    	std::vector<int> pg(n, -1), pref_min(n);
    	
    	for (int i = 0; i < n; i++)
    	{
    		if (i == 0)
    			pref_min[0] = nums[0];
    		else
    			pref_min[i] = std::min(pref_min[i - 1], nums[i]);
    	}
    	
    	std::stack<int> s;
    	
    	for (int i = 0; i < n; i++)
    	{
    		while (!s.empty() and nums[s.top()] <= nums[i])
    			s.pop();
    		
    		if (!s.empty())
	    		pg[i] = s.top();
	    	
	    	s.push(i);
    	}
    	
    	for (int k = n - 1; k > 1; k--)
    	{
    		int j = pg[k];
    		
    		if (j <= 0)
    			continue;
    		
    		int numsj = nums[j];
    		int numsi = pref_min[j - 1];
    		
    		if (numsi < nums[k])
    			return true;
    	}
    	
    	return false;
    }
};

int main()
{
	Solution sol;
	vector<int> a {1, 0, 1, -4, -2};
	cout << sol.find132pattern(a);
	return 0; 
}    