#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

bool isPrime(auto x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

std::vector<int> prime;
constexpr int N = 180;

void solve()
{
    i64 l, r, k;
    std::cin >> l >> r >> k;

    i64 left = l, right = r;
    i64 ans = -1;
    
    auto f = [&](std::string s)
    {
        int n = std::size(s);
        std::vector dp(n + 1, std::vector(2, std::vector<i64>(N)));
        dp[n][0][0] = dp[n][1][0] = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int tight = 0; tight < 2; tight++)
            {
                for (int sum = 0; sum < N; sum++)
                {
                    int ub = tight ? s[i] - '0' : 9;
                    for (int d = 0; d <= ub; d++)
                    {
                        if (sum - d >= 0)
                            dp[i][tight][sum] += dp[i + 1][tight & (d == ub)][sum - d]; 
                    }
                }
            }
        }

        return dp;
    }; 

    l--;
    auto dpL = f(std::to_string(l));

    auto good = [&](i64 mid)
    {
        i64 total = 0;
        auto dpR = f(std::to_string(mid));

        for (int p : prime)
            total += dpR[0][1][p] - dpL[0][1][p];
        
        return total >= k;
    };

    while (left <= right)
    {
        i64 mid = (left + right) / 2;
        if (good(mid))
            ans = mid, right = mid - 1;
        else
            left = mid + 1;
    }

    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (int i = 2; i < N; i++)
    {
        if (isPrime(i))
            prime.emplace_back(i);
    }

    int t;
    std::cin >> t;

    while (t--)
        solve();

    return 0;
}