#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        stack<int> st;
        int n = num.size();

        for(int i = 0; i < num.size(); i++)
        {
            while(!st.empty() and k and (s.top() > num[i] - '0'))
                st.pop(), k--;
            
            if (!st.empty() or num[i] != '0')
                st.push(num[i] - '0');
        }

        while(!st.empty() and k)
            st.pop(), k--;
        
        if (st.empty())
            return "0";

        while(!st.empty())
        {
            num[n - 1] = st.top();
            st.pop();
            n--;
        }

        return num.substr(n);
    }
};

int main()
{
    return 0;
}