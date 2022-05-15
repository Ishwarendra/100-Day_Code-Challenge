#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
  		int n = nums.size();
  		
  		if (n < 3)
  			return 0;
  			
  		int cnt = 0, diff = 0;
  		
  		for(int i = 0; i < n - 2; i++)
  		{
  			diff = nums[i + 1] - nums[i];
  			
  			for(int j = i + 2; j < n; j++)
  			{
  				if (diff == nums[j] - nums[j - 1])
  					cnt++;
  				else
  					break;
  			}
  		}
  		
  		return cnt;
    }
};

int main()
{
	
	return 0; 
}    