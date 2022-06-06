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
  int countSubstrings(string s)
  {
    int n = s.length();

    std::vector<std::vector<int>> dp(n, std::vector<int>(n));

    for (int i = 0; i < n; i++)
    {
      dp[i][i] = 1;
      if (i)
        dp[i - 1][i] = s[i - 1] == s[i];
    }

    for (int len = 3; len <= n; len++)
    {
      for (int i = 0; i < n - len + 1; i++)
        dp[i][i + len - 1] = dp[i + 1][i + len - 2] and s[i] == s[i + len - 1];       
    }
    
    int ans = 0;
    
    for (int i = 0; i < n; i++)
    {
      for (int j = i; j < n; j++)
        ans += dp[i][j];
    }      
    
    return ans;
  }
};

int main()
{
  Solution sol;
  sol.countSubstrings("aaa");
  return 0;
}