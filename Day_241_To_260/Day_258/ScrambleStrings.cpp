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
    bool isScramble(std::string s1, std::string s2)
    {
        int n = std::size(s1);
        std::vector dp(n, std::vector(n, std::vector(n, std::vector(n, -1))));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                dp[i][i][j][j] = s1[i] == s2[j];
        }

        std::function<int(int i, int j, int k, int l)> f;
        f = [&](int i, int j, int k, int l) -> int
        {
            int len = j - i + 1;

            if (l - k + 1 != len)
                return 0;
            if (i > j or k > l)
                return 0;

            int &ans = dp[i][j][k][l];
            if (ans != -1)
                return ans;

            ans = 0;
            for (int x = 1; x < len; x++)
            {
                ans |= f(i + x, j, k + x, l)   
                    & f(i, i + x - 1, k, k + x - 1);

                ans |= f(i + x, j, k, k + j - i - x)
                    & f(i, i + x - 1, l - x + 1, l);
            }     

            return ans;
        };

        int ans = f(0, n - 1, 0, n - 1);
        return ans;
    }
};

int main()
{
    Solution sol;

    std::string s, t;
    std::cin >> s >> t;

    std::cout << sol.isScramble(s, t);
    return 0; 
}    