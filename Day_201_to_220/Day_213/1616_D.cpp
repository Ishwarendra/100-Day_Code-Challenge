#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    int x;
    std::cin >> x;

    for (int i = 0; i < n; ++i)
        a[i] -= x;
    
    std::vector<int> take(n, 1);
    for (int i = 1; i < n; i++)
    {
        // 2 and 3 lengths decide
        if (!take[i - 1])
            continue;
        if (a[i] + a[i - 1] < 0)
            take[i] = 0;

        if (i - 2 >= 0)
        {
            if (!take[i - 2])
                continue;
            if (a[i] + a[i - 1] + a[i - 2] < 0)
                take[i] = 0;
        }
    }

    std::cout << std::accumulate(std::begin(take), std::end(take), 0) << "\n";
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