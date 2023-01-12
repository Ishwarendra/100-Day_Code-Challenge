#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution {
public:
    bool isItPossible(std::string word1, std::string word2)
    {
        std::map<int, int> cnt1, cnt2;

        for (auto &ch : word1)
            cnt1[ch - 'a']++;

        for (auto &ch : word2)
            cnt2[ch - 'a']++;

        auto erase0 = [](std::map<int, int> &m)
        {
            std::vector<int> rem;
            for (auto [num, f] : m)
                if (f == 0)
                    rem.emplace_back(num);

            for (int x : rem)
                m.erase(x);
        };

        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                erase0(cnt1);
                erase0(cnt2);
                if (!cnt1[i] or !cnt2[j])
                    continue;

                cnt1[i]--, cnt2[j]--;
                cnt1[j]++, cnt2[i]++;
   
                if (cnt1[i] == 0)
                    cnt1.erase(i);
                if (cnt2[j] == 0)
                    cnt2.erase(j);

                int ndistinct1 = std::size(cnt1), ndistinct2 = std::size(cnt2);
                if (ndistinct1 == ndistinct2)
                    return true;

                cnt1[i]++, cnt2[j]++;
                cnt1[j]--, cnt2[i]--;
            }
        }

        return false;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string a, b;
    std::cin >> a >> b;

    Solution solution;
    std::cout << solution.isItPossible(a, b);

    return 0;
}