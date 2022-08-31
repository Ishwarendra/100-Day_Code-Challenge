#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(4 * n);
    for (int i = 0; i < 4 * n; ++i)  
        std::cin >> a[i];

    std::sort(std::begin(a), std::end(a));
    int area = a[0] * a.back();

    for (int i = 0, j = 4 * n - 1; i < 4 * n - 1 and j > 0; i += 2, j -= 2)
    {
        if (a[i] * a[j] != area || a[i] != a[i + 1] || a[j] != a[j - 1])
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