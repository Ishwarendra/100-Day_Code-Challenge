#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution 
{
public:
    i64 distinctNames(std::vector<std::string>& ideas) 
    {
        i64 ans = 0;

        std::map<int, std::set<std::string>> m;
        for (auto idea : ideas)
            m[idea[0] - 'a'].emplace(idea.substr(1));

        for (int i = 0; i < 26; i++)
        {
            for (int j = i + 1; j < 26; j++)
            {
                int common = 0;
                for (auto s : m[i])
                    common += m[j].count(s);

                int sz_i = std::size(m[i]);
                int sz_j = std::size(m[j]);
                ans += 2LL * (sz_i - common) * (sz_j - common);
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    int n;
    std::cin >> n;

    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::cout << sol.distinctNames(a);
    return 0; 
}    