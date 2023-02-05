#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) 
    {
        int n = std::size(s1), m = std::size(s2);
        
        auto getFreq = [&](std::string &s)        
        {
            std::array<int, 26> cnt{};
            for (auto &ch : s)
                cnt[ch - 'a']++;
            return cnt;
        };

        auto cnt1 = getFreq(s1);
        auto cnt2 = getFreq(s2);

        for (int i = 0; i < 26; i++)
        {
            if (cnt1[i] > cnt2[i])
                return false;
        }

        std::fill(std::begin(cnt2), std::end(cnt2), 0);

        for (int i = 0, j = 0; j < m;)
        {
            cnt2[s2[j] - 'a']++;
            j++;

            if (j - i == n)
            {
                if (cnt1 == cnt2)
                    return true;

                cnt2[s2[i] - 'a']--;
                i++;
            }
        }

        return false;    
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    
    
    return 0;
}