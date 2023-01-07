#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution {
public:
    int maxIceCream(std::vector<int>& costs, int coins) 
    {
        std::sort(std::begin(costs), std::end(costs));

        int n = std::size(costs);
        int ans = 0;
        for (int i = 0; i < n; i++)    
        {
            if (coins < costs[i])
                break;

            coins -= costs[i];
            ans++;
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