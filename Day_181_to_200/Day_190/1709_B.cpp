#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    std::vector<i64> pref(n), suff(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
        if (i)
            pref[i] = std::max(0LL, 1LL * a[i - 1] - a[i]);
    }

    for (int i = n - 2; i >= 0; i--)
        suff[i] = std::max(0LL, 1LL * a[i + 1] - a[i]);

    // print(suff)
    for (int i = 1; i < n; i++)
        pref[i] += pref[i - 1];
    for (int i = n - 2; i >= 0; i--)
        suff[i] += suff[i + 1];

    for (int i = 0; i < m; ++i)
    {
        int s, t;
        std::cin >> s >> t;
        s--, t--;

        if (s <= t)
            std::cout << pref[t] - pref[s] << "\n";
        else
            std::cout << suff[t] - suff[s] << "\n";
    }
    
    return 0;
}