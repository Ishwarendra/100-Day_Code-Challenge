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
    int maxEnvelopes(vector<vector<int>>& envelopes) 
    {
		std::sort(envelopes.begin(), envelopes.end(),
			[&](const vector<int> &a, const vector<int> &b)
			{
				if (a[0] == b[0])
					return a[1] > b[1];
				
				return a[0] < b[0];
			});   
		
		int ans = 0;
		std::vector<int> lis;
		
		for (auto envelope : envelopes)
		{
			int w = envelope[0], h = envelope[1];
			
			auto lb = std::lower_bound(lis.begin(), lis.end(), h) - lis.begin();
			
			if (lb == lis.size())
				lis.push_back(h);
			else
				lis[lb] = h;
		}
		
		return lis.size();
    }
};

int main()
{
	return 0; 
}    