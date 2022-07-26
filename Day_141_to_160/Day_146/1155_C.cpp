#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<i64> x(n), p(m);

    for (int i = 0; i < n; ++i)
        std::cin >> x[i];

    for (int i = 0; i < m; ++i)
        std::cin >> p[i];

    i64 g = 0;

    for (int i = 0; i < n - 1; ++i)
        g = std::gcd(g, x[i + 1] - x[i]);

    for (int i = 0; i < m; ++i)
    {
        if (g % p[i] == 0)
        {
            std::cout << "YES\n";
            std::cout << x[0] << " " << i + 1 << "\n";
            return;
        }
    }

    std::cout << "NO\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    
    while(t--)
        solve();
    
    return 0;
}