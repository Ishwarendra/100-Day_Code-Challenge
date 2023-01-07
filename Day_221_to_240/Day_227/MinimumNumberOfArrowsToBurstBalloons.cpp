#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution {
public:
    int findMinArrowShots(std::vector<std::vector<int>>& points) 
    {
        std::sort(std::begin(points), std::end(points));
        int n = std::size(points);
        int ans = 0;

        for (int i = 0; i < n; )
        {
            int L = points[i][0], R = points[i][1];
            int j = i;

            while (j < n and L <= R)
            {
                L = std::max(L, points[j][0]);
                R = std::min(R, points[j][1]);
                j++;
            }

            j -= L > R;
            if (j == i)
                ans++, i = j + 1;
            else
            {
                ans++;
                i = j;
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