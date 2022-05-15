#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

class Solution
{
    vector<string> numString;
    vector<string> ans;

public:
    Solution()
    {
        numString = {"",
                     "", "abc", "def",
                     "ghi", "jkl", "mno",
                     "pqrs", "tuv", "wxyz"};
    }

    void generateComb(const string &digits)
    {
        ans.push_back("");

        for (const char &dig : digits)
        {
            int digit = dig - '0';

            vector<string> temp;
            for (const char &ch : numString[digit])
            {

                for (auto res_char : ans)
                {
                    temp.push_back(res_char + ch);
                }
            }
            ans = temp;
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.length() == 0)
            return ans;

        generateComb(digits);

        return ans;
    }
};

vector<string> leetw

int main()
{
    return 0;
}