#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution 
{
public:
    std::string addBinary(std::string a, std::string b) 
    {
        std::string res;
        int n = std::size(a), m = std::size(b);

        int i = n - 1, j = m - 1;
        int carry = 0;
        while (i >= 0 or j >= 0) 
        {
            int a_i = (i >= 0 ? a[i] - '0' : 0);
            int b_j = (j >= 0 ? b[j] - '0' : 0);
            int sum = a_i + b_j + carry;

            res += std::to_string(sum % 2);
            carry = sum / 2;

            i--, j--;
        }

        if (carry)
            res += '1';

        std::reverse(std::begin(res), std::end(res));
        return res;
    }
};

int main()
{
    return 0; 
}    