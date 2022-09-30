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
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    int ans = 2e9;

    for (int i = 0; i < n; ++i)
    {
        int min = 1e9, second_min = 1e9;
        for (int j = 0; j < n; j++)
        {
            if (j == i)
                continue;

            if (std::abs(a[j] - a[i]) < min)
                second_min = min, min = std::abs(a[j] - a[i]);
            else if (std::abs(a[j] - a[i]) < second_min)
                second_min = std::abs(a[j] - a[i]);
        }

        ans = std::min(ans, second_min + min);
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