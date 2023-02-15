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
    std::vector<int> addToArrayForm(std::vector<int>& num, int k) 
    {
        std::vector<int> res;
        int n = std::size(num);

        int carry = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            int sum = num[i] + k + carry;
            res.emplace_back(sum % 10);
            carry = sum / 10;
            k = 0;
        }

        while (carry)
        {
            res.emplace_back(carry % 10);
            carry /= 10;
        }

        std::reverse(std::begin(res), std::end(res));
        return res;
    }
};

int main()
{
    return 0; 
}    