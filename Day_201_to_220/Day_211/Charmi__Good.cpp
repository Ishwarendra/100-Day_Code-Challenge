#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector<int> dp(n, inf);
    dp[0] = a[0];
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n and j <= i + a[i]; j++)
            dp[j] = std::min(dp[j], dp[i] | a[j]);
    }
    
    std::cout << (dp[n - 1] == inf ? -1 : dp[n - 1]);
    
    return 0;
}