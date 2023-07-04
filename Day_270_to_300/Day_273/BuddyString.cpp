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
    bool buddyStrings(std::string s, std::string goal) 
    {
        int n = std::size(s);
        if (n != std::size(goal))
            return false;

        std::vector<int> unequal;
        std::array<int, 26> cnt{};
        for (int i = 0; i < n; i++)
        {
            if (s[i] != goal[i])
                unequal.emplace_back(i);
            else
                cnt[s[i] - 'a']++;
        }

        int max = *std::max_element(std::begin(cnt), std::end(cnt));
        if (std::size(unequal) == 2)
            return s[unequal[0]] == goal[unequal[1]] and s[unequal[1]] == goal[unequal[0]];
        else if (unequal.empty())
            return max > 1;
        return false;
    }
};

int main()
{
    return 0; 
}    