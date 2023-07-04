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
    int maximumRequests(int n, std::vector<std::vector<int>>& requests) 
    {
        std::vector<int> a(n);
        for (auto request : requests)
        {
            int u = request[0], v = request[1];
            a[u]--;
            a[v]++;
        }

        int m = std::size(requests);
        auto get = [&](int mask)
        {
            auto getBit = [&](int num, int pos) { return num >> pos & 1; };
            auto b = a;
            for (int i = 0; i < m; i++)
            {
                if (getBit(mask, i))
                {
                    int u = requests[i][0], v = requests[i][1];
                    b[u]++, b[v]--;
                }
            }

            for (int i = 0; i < n; i++)
            {
                if (b[i] != 0)
                    return false;
            }

            return true;
        };

        int ans = m;
        for (int mask = 0; mask < (1 << m); mask++)
        {
            if (get(mask))
                ans = std::min(ans, __builtin_popcount(mask));
        }

        return ans;
    }
};

int main()
{
    return 0; 
}    