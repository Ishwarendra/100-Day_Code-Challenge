#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution
{
    const int inf = 1e9;
    int power(int a, int b)
    {
        int res = 1;
        for (int i = 0; i < b; i++)
            res *= a;
        return res;
    }
public:
    int tallestBillboard(std::vector<int>& rods)
    {
        int n = std::size(rods);
        auto getBit = [&](int x, int pos)
        {
            while (pos--)
                x /= 3;
            return x % 3;
        };

        int end1 = power(3, n / 2 + 1);
        int end2 = power(3, n - n / 2);

        std::unordered_map<int, int> left;
        int ans = 0;
        for (int i = 0; i < end1; i++)
        {
            int sum = 0, p1 = 0;
            int mask = i;
            for (int pos = 0; pos < n / 2; pos++)
            {
                if (getBit(mask, pos) == 1)
                    sum += rods[pos], p1 += rods[pos];
                else if (getBit(mask, pos) == 2)
                    sum -= rods[pos];
            }

            left[sum] = std::max(left[sum], p1);
            if (sum == 0)
                ans = std::max(ans, p1);
        }

        for (int i = 0; i < end2; i++)
        {
            int mask = i;
            int s1 = 0, s2 = 0;
            for (int pos = n / 2; pos < n; pos++)
            {
                if (getBit(mask, pos - n / 2) == 1)
                    s1 += rods[pos];
                else if (getBit(mask, pos - n / 2) == 2)
                    s2 += rods[pos];
            }

            int sum = s1 - s2;
            if (left.count(-sum))
                ans = std::max(ans, s1 + left[-sum]);
            if (sum == 0)
                ans = std::max(ans, s1);
        }

        return ans;
    }
};

int main()
{
    return 0;
}