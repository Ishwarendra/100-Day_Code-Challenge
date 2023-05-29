#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int x, y, z;
    std::cin >> x >> y >> z;

    i64 have = 1LL * z * (z + 1) / 2 + x;
    std::cout << (have >= y ? "YES\n" : "NO\n");  
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