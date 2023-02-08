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
    int totalFruit(std::vector<int>& fruits) 
    {
        int n = std::size(fruits);
        std::array<int, 2> a{-1, -1};

        int ans = 0;
        std::map<int, int> m;

        for (int left = 0, right = 0; right < n;)
        {
            while (right < n and std::size(m) <= 2)
            {
                m[fruits[right]]++;
                right++;
            }

            if (std::size(m) > 2)
                m.erase(fruits[--right]);

            int cur_ans = 0;
            for (auto &[num, f] : m)
                cur_ans += f;

            ans = std::max(ans, cur_ans);

            while (std::size(m) == 2)
            {
                m[fruits[left]]--;
                if (m[fruits[left]] == 0)
                    m.erase(fruits[left]);

                left++;
            }
        }

        return ans;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    
    
    return 0;
}