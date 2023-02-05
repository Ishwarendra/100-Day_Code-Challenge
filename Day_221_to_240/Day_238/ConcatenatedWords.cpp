#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution {
public:
    std::vector<std::string> findAllConcatenatedWordsInADict(std::vector<std::string>& words)
    {
        std::vector<std::string> ans;
        std::set<std::string> s(std::begin(words), std::end(words));

        for (auto &t : words)
        {
            int n = std::size(t);

            std::vector dp(n, std::vector<int>(n));

            for (int len = 1; len <= n; len++)
            {
                for (int i = 0; i + len - 1 < n; i++)
                {
                    int j = i + len - 1;
                    dp[i][j] = s.count(t.substr(i, len));
                    for (int k = i; k < j and len >= 2; k++)
                        dp[i][j] |= (dp[i][k] & dp[k + 1][j]);
                }
            }

            for (int pos = 0; auto p : dp)
            {
                std::cout << (pos++) << ": ";
                for (auto x : p)
                    std::cout << x << ' ';
                std::cout << "\n";
            }

            for (int i = 0; i < n - 1; i++)
            {
                {
                    ans.emplace_back(t);
                    break;
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

    // std::vector<std::string> b
    // {
    //     "cat", "cats", "catsdogcats", "dog", "dogcatsdog", 
    //     "hippopotamuses", "rat", 
    //     "ratcatdogcat"
    // };

    // std::vector<std::string> b {"rat", "cat", "ratcatg"};

    Solution sol;
    print(sol.findAllConcatenatedWordsInADict(b));


    return 0;
}