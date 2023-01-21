#include "bits/stdc++.h"

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
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    std::vector<int> b(n + 1);
    b[0] = a[0], b[n] = a[n - 1];

    for (int i = 1; i < n; i++)
        b[i] = std::lcm(a[i - 1], a[i]);

    for (int i = 0; i < n; i++)
    {
        if (std::gcd(b[i], b[i + 1]) != a[i])
        {
            std::cout << "NO\n";
            return;
        }
    }

    std::cout << "YES\n";
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