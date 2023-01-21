#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution {
public:
    std::vector<std::string> restoreIpAddresses(std::string s)
    {
        int n = std::size(s);
        std::vector<std::string> ans;

        if (n > 12)
            return ans;

        auto between = [&](int x, int l, int r)
        {
            return l <= x and x <= r;
        };

        auto validNum = [&](std::string t)
        {
            if (std::size(t) <= 1)
                return true;

            return t[0] != '0' and between(std::stoll(t), 0, 255);
        };

        auto check = [&](std::string t)
        {
            std::string num;
            for (int i = 0; i <= std::size(t); i++)
            {
                if (t[i] == '.' or i == std::size(t))
                {
                    if (!validNum(num))
                        return false;
                    num.clear();
                }
                else
                    num += t[i];
            }

            return true;
        };

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n - 1; k++)
                {
                    std::string t;
                    for (int x = 0; x < n; x++)
                    {
                        t += s[x];
                        if (x == i or x == j or x == k)
                            t += '.';
                    }

                    if (check(t))
                    {
                        ans.emplace_back(t);
                    }
                }
            }
        }

        return ans;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution sol;
    std::string s;
    std::cin >> s;

    print(sol.restoreIpAddresses(s));

    return 0;
}