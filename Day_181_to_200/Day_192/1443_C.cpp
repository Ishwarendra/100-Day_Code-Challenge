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

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)  
        std::cin >> a[i];

    for (int i = 0; i < n; ++i)
        std::cin >> b[i];

    i64 left = 1, right = 1e15;
    i64 ans = 0;

    auto good = [&](i64 mid)
    {
        i64 sum = 0;
        for (int i = 0; i < n; i++)
            if (a[i] * 1LL > mid)
                sum += b[i];

        return sum <= mid;
    };

    while (left <= right) 
    {
        i64 mid = (left + right) >> 1;

        if (good(mid))
            ans = mid, right = mid - 1;
        else
            left = mid + 1;
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