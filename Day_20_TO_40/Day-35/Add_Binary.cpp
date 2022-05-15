#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

class Solution {
    void format(string &a, string &b)
    {
        string tmp;
        int m = min(a.length(), b.length()), n = max(a.length(), b.length());
        while(m++ < n)
            tmp += '0';
        if (a.length() < b.length())
            a = tmp + a;
        else 
            b = tmp + b;
    }

    pair<char, char> add(char a, char b, char c)
    {
        // return {sum-dig, carry}
        int sum = (a - '0') + (b - '0') + (c - '0');
        if (sum == 0)
            return {'0', '0'};
        else if (sum == 1)
            return {'1', '0'};
        else if (sum == 2)
            return {'0', '1'};
        else 
            return {'1', '1'};
    }
public:
    string addBinary(string a, string b) {
        format(a, b);
        string ans;
        char carry = '0';
        for(int i = a.length() - 1; i > = 0; --i)
        {
            pair<char, char> val = add(a[i], b[i], carry);
            ans = val.first + ans;
            carry = val.second;
        }

        if (carry == '1')
            ans ='1' + ans;
        return ans;
    }
};

int main()
{
    return 0;
}