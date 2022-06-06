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
    int longestValidParentheses(string s) 
    {
   		std::stack<int> st;
   		st.push(-1);
   		
   		int ans = 0, cur = 0, n = s.size();
   		
   		for (int i = 0; i < n; ++i)   		     
   		{
   			if (s[i] == '(' or st.empty())
   				st.push(i);
   			else
   			{
   				ans = std::max(ans, i - st.top());
   				st.pop();
   			}
   		}
   		
   		return ans;
    }
};

int main()
{
	return 0; 
}    