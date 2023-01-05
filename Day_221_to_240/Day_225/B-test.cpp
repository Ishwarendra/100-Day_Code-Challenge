#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int MOD = 1e9 + 7;

void solve()
{
    int n;
    std::cin >> n;

    i64 ans = n * (2 * n + 1) * (n + 1) / 6;
    ans -= n * (n + 1) / 2;
    
    std::cout << (ans * 2022LL) % MOD << "\n";  
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