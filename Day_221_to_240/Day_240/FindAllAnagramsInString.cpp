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
    std::vector<int> findAnagrams(std::string s, std::string p) 
    {
        int n = std::size(s), m = std::size(p);
        std::vector<int> res;

        if (m > n)
            return res;

        std::array<int, 26> cnt1{}, cnt2{};
        for (int i = 0; i < m - 1; i++)
        {
            cnt1[s[i] - 'a']++;
            cnt2[p[i] - 'a']++;
        }

        cnt2[p.back() - 'a']++;

        for (int i = m - 1; i < n; i++)
        {
            cnt1[s[i] - 'a']++;

            if (cnt1 == cnt2)
                res.emplace_back(i - m + 1);

            cnt1[s[i - m + 1] - 'a']--;
        }

        return res;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    
    
    return 0;
}