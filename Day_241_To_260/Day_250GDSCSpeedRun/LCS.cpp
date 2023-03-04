#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    for (int i = 0; i < m; i++)
        std::cin >> b[i];

    std::vector dp(n + 1, std::vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int i = n, j = m;
    std::vector<int> lcs;
    while (i >= 1 and j >= 1)
    {
        if (dp[i][j] == dp[i - 1][j - 1] + 1 and a[i - 1] == b[j - 1])
            lcs.emplace_back(a[i - 1]), i--, j--;
        else if (dp[i][j] == dp[i - 1][j])
            i--;
        else
            j--;
    }

    std::reverse(std::begin(lcs), std::end(lcs));
    for (auto x : lcs)
        std::cout << x << ' ';
    
    return 0;
}