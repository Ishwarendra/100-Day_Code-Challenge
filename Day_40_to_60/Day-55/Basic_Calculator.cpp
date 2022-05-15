#include <bits/stdc++.h>
using namespace std;

class Solution {
    string remove_spaces(string &s)
    {
        string beautified;
        for(char &ch : s)
        {
            if (ch != ' ')
                beautified += ch;
        }

        return beautified;
    }

    pair<int, int> calculate(string &s, int id)
    {
        int cur_num = 0, sum = 0, sign = 1;
        int i = id;

        for(; i < s.length(); i++)
        {
            char cur_char = s[i];

            if (cur_char == ' ')
                continue;
            else if (cur_char == ')')
                break;
            else if (cur_char == '(')
            {
                pair<int, int> res = calculate(s, i + 1);
                sum += res.first * sign;
                i = res.second;
            }
            else if (cur_char == '+')
            {
                sum = sum + cur_num * sign;
                cur_num = 0;
                sign = 1;
            }
            else if (cur_char == '-')
            {
                sum = sum + cur_num * sign;
                cur_num = 0;
                sign = -1;
            }
            else
                cur_num = cur_num*10 + (cur_char - '0');
        }

        sum = sum + (cur_num * sign);
        return {sum, i};
    }

public:
    int calculate(string s) {
        // s = remove_spaces(s);
        pair<int, int> ans = calculate(s, 0); 

        return ans.first;
    }
};

int main()
{
    return 0;
}