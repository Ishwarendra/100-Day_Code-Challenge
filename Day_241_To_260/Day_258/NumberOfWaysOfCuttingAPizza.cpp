#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution 
{
    const int MOD = 1e9 + 7;
public:
    int ways(std::vector<std::string>& pizza, int k) 
    {
        int n = std::size(pizza);
        int m = std::size(pizza[0]);
        std::vector dp(n, std::vector(m, std::vector(k, -1)));        

        std::function<int(int, int, int)> f;
        f = [&](int i, int j, int cuts) -> int
        {
            int &ans = dp[i][j][cuts];

            if (cuts == 0)
            {
                // (i, j) to (n - 1, m - 1) if atleast one apple then ok
                int sum = 0;
                for (int p = i; p < n; p++)
                {
                    for (int q = j; q < m; q++)
                    {
                        sum += pizza[p][q] == 'A';
                        if (sum > 0)
                            return 1;
                    }
                }

                return sum > 0;
            }

            if (ans != -1)
                return ans;
            ans = 0;

            int sum = 0;

            // horizontal cut
            for (int id = i + 1; id < n; id++)
            {
                for (int p = j; p < m; p++)
                    sum += pizza[id - 1][p] == 'A';

                if (sum > 0)
                    ans = (ans + f(id, j, cuts - 1)) % MOD;
            }

            sum = 0;
            // vertical cut
            for (int id = j + 1; id < m; id++)
            {
                for (int p = i; p < n; p++)
                    sum += pizza[p][id - 1] == 'A';

                if (sum > 0)
                    ans = (ans + f(i, id, cuts - 1)) % MOD;
            }

            return ans;
        };

        return f(0, 0, k - 1);
    }
};

int main()
{
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::string> pizza(n);
    for (int i = 0; i < n; i++)
        std::cin >> pizza[i];

    Solution solution;
    std::cout << solution.ways(pizza, k) << "\n";
    return 0; 
}    