#include <bits/stdc++.h>
using namespace std;

// Increase all ele
// if max ele is even then divide by 2 and find new ans
// if max ele is odd you are done

class Solution {
public:
	int minimumDeviation(vector<int>& nums) {
		
		int n = nums.size();
		
		int maxi = INT_MIN, mini = INT_MAX;
		
		for(int &x: nums)
		{
			if (x & 1)
				x *= 2;
			
			maxi = max(maxi, x);
			mini = min(mini, x);
		}
		
		
		int ans = maxi - mini;
		
		priority_queue<int> pq;
		
		for(int &x : nums)
			pq.push(x);
		
		while(pq.top() % 2 == 0)
		{
			int top = pq.top();
			pq.pop();
			
			ans = min(ans, top - mini);
			top /= 2;
			mini = min(mini, top);
			
			pq.push(top);
		}
		
		return min(ans, pq.top() - mini);
	}
};

int main()
{
	return 0;
}