#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution 
{
    constexpr static int inf = 1e9;
public:
    std::vector<int> smallestSufficientTeam(std::vector<std::string>& req_skills, 
        std::vector<std::vector<std::string>>& people) 
    {
        std::map<std::string, int> pos;
        for (int i = 0; i < std::size(req_skills); i++)
            pos[req_skills[i]] = i;

        int n = std::size(people);
        std::vector<int> a(n);

        for (int i = 0; i < n; i++)
        {
            auto skills = people[i]; 
            for (auto skill : skills)
            {
                if (!pos.count(skill))
                    continue;
                a[i] |= 1 << pos[skill];
            }       
        }

        auto chkmin = [&](int &a, int b)
        {
            if (a > b)
            {
                a = b;
                return true;
            }

            return false;
        };

        int m = std::size(req_skills);
        std::vector par(1 << m, std::array<int, 2>());
        std::vector dp(1 << m, inf);
        for (int i = 0; auto skill_mask : a)
        {
            dp[skill_mask] = 1;
            par[skill_mask] = {0, i};
            i++;
        }

        for (int mask = 0; mask < (1 << m); mask++)
        {
            for (int i = 0; i < n; i++)
            {
                if (chkmin(dp[mask | a[i]], dp[mask] + 1))
                    par[mask | a[i]] = {mask, i};
            }
        }

        std::vector<int> ans;

        int mask = (1 << m) - 1;
        while (mask != 0)
        {
            ans.emplace_back(par[mask][1]);
            mask = par[mask][0];
        }

        return ans;
    }
};

int main()
{
    return 0; 
}    