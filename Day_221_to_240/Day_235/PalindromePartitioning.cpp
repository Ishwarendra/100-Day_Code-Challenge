#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution {
public:
    std::vector<std::vector<std::string>> partition(std::string s) 
    {
        std::vector<std::vector<std::string>> ans;
        int n = std::size(s);

        std::vector<std::vector<int>> isPalindrome(n, std::vector<int>(n));    
        for (int i = 0; i < n; i++)
        {
            isPalindrome[i][i] = 1;
            if (i + 1 < n)
                isPalindrome[i][i + 1] = s[i] == s[i + 1];
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                if (j - i + 1 < 3)
                    continue;

                isPalindrome[i][j] = (isPalindrome[i + 1][j - 1] and (s[i] == s[j]));
            }
        }

        std::vector<std::string> temp;
        std::function<void(int)> f = [&](int i)
        {
            if (i == n)
            {
                if (!temp.empty())
                    ans.emplace_back(temp);
                return;
            }

            for (int j = i; j < n; j++)
            {
                if (isPalindrome[i][j])
                {
                    temp.push_back(s.substr(i, j - i + 1));
                    f(j + 1);
                    temp.pop_back();
                }
            }
        }; f(0);

        return ans;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    
    
    return 0;
}