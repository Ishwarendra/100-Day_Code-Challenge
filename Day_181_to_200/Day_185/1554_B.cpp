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
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)  
        std::cin >> a[i];

    i64 ans = -1e9;
    for (int i = std::max(0, n - 2 * k - 1); i < n; i++)
    {
        for (int j = i + 1; j < n; ++j)
            ans = std::max(ans, 1LL * (i + 1) * (j + 1) - 1LL * k * (a[i] | a[j]));
    }

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