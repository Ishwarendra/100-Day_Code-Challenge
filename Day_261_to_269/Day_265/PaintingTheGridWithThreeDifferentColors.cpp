#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution 
{
    const int MOD = 1e9 + 7;
    std::array<int, 6> pw3 {1, 3, 9, 27, 81, 243};
    int getBit(int mask, int pos)
    {
        mask /= pw3[pos];
        return mask % 3;
    }
    void add(int &x, int y)
    {
        x = (x + y) % MOD;
    }
public:
    int colorTheGrid(int m, int n) 
    {
        std::vector dp(pw3[m], 1);
        std::vector<int> valid_mask;
        for (int i = 0; i < pw3[m]; i++)
        {
            for (int pos = 1; pos < m; pos++)
                dp[i] &= getBit(i, pos) != getBit(i, pos - 1);

            if (dp[i])
                valid_mask.emplace_back(i);
        }

        for (int i = 0; i < n - 1; i++)
        {
            std::vector ndp(pw3[m], 0);
            for (int mask1 : valid_mask)
            {
                for (int mask2 : valid_mask)
                {
                    int valid = 1;
                    for (int pos = 0; pos < m; pos++)
                    {
                        valid &= getBit(mask2, pos) != getBit(mask1, pos);
                        if (!valid)
                            break;
                    }

                    add(ndp[mask2], valid * dp[mask1]);
                }
            }

            std::swap(ndp, dp);
        }

        int ans = 0;

        for (int i = 0; i < pw3[m]; i++)
            add(ans, dp[i]);

        return ans;
    }
};

int main()
{
    int m, n;
    std::cin >> m >> n;

    Solution sol;
    std::cout << sol.colorTheGrid(m, n);
    return 0; 
}    