#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution 
{
public:
    int shipWithinDays(std::vector<int>& weights, int days) 
    {
        int n = std::size(weights);
        int left = 0, right = 1e9;
        int ans = 1;

        auto good = [&](int mid)
        {
            int need = 1, cost = 0;
            for (int i = 0; i < n; i++)
            {
                if (weights[i] > mid)
                    return false;

                if (cost + weights[i] <= mid)
                    cost += weights[i];
                else
                    need++, cost = weights[i];
            }

            return need <= days;
        };

        while (left <= right)
        {
            int mid = (left + right) >> 1;
            if (good(mid))
                ans = mid, right = mid - 1;
            else
                left = mid + 1;
        }

        return ans;
    }
};

int main()
{
    return 0; 
}    