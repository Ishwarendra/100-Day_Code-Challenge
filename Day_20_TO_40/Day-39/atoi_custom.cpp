#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

class Solution {
public:
    int myAtoi(string s) {
        int start_id = 0, n = s.length();
        for(int i = 0; i < n; i++)
        {
            if (s[i] != ' ')
            {
                start_id = i;
                break;
            }
        }

        bool negative = false;
        int ans = 0;
        for(int i = start_id; i < n; i++)
        {
            if (s[i] == '-')
                negative = true;
            else
            {
                if (s[i] == '+')
                    continue;
               else if (s[i] - '0' >= 0 and s[i] - '0' <= 9){
                    if (ans > INT_MAX/10 or (ans == INT_MAX/10) and (s[i] - '0' > INT_MAX % 10))
                        return (negative ? INT_MIN : INT_MAX);
                    ans = ans * 10 + (s[i] - '0'); 
               }
                else
                    break;
            }
        }

        return (negative ? -ans : ans);
    }
};

int main()
{
    return 0;
}