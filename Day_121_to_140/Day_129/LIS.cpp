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
  int lengthOfLIS(vector<int>& nums) {    
    std::vector<int> lis;
    int n = nums.size();
    
    for (int i = 0; i < n; ++i)
    {
      auto lb = std::lower_bound(lis.begin(), lis.end(), nums[i]);
      
      if (lb == lis.end())
        lis.push_back(nums[i]);
      else
        lis[lb - lis.begin()] = nums[i];
    }
    
    return lis.size();
  }
};

int main()
{
  return 0;
}