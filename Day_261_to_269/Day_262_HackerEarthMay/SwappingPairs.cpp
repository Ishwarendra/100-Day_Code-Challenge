#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    i64 sum = 0;
    std::vector<int> d(n);
    for (int i = 0; i < n; i++)  
    {
        int b;
        std::cin >> d[i] >> b;
        sum += d[i];
        d[i] = b - d[i];
    }

    constexpr int N = 1e6;
    std::bitset<N> dp;
    dp[sum] = 1;

    for (int i = 0; i < n; i++)
    {
        if (d[i] >= 0)
            dp |= (dp << d[i]);
        else
            dp |= (dp >> -d[i]);
    }

    std::cout << (dp[m] ? "YES\n" : "NO\n");
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}