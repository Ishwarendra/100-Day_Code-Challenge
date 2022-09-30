#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    i64 xr = 0;
    for (int i = 0; i < n; i++)  
    {
        std::cin >> a[i];
        xr ^= a[i];
    }

    i64 sum = std::accumulate(std::begin(a), std::end(a), 0LL);

    std::cout << 2 << "\n" << xr << " " << sum + xr << "\n";
    assert(sum + xr * 2LL + sum == (sum + xr) * 2LL);
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