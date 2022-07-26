#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    if (n > m)  
        std::swap(n, m);

    if (n == 1)
    {
        std::cout << (m <= 2 ? m - 1 : -1) << "\n";
        return;
    }

    i64 ans = 2LL * n - 2;
    int cur_i = n, cur_j = n;

    int more = m - cur_j;
    if (more % 2)
        ans++, more--;

    ans += (more / 2) * 4LL;
    std::cout << ans << "\n";
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