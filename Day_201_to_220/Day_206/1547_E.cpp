#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(k);
    std::map<int, int> m;
    for (int i = 0; i < k; i++)
    {
        std::cin >> a[i];
        a[i]--;
    }

    for (int i = 0; i < k; i++)
    {
        int x;
        std::cin >> x;
        m[a[i]] = x; 
    }

    constexpr int inf = 1e9 + 1e7;
    std::vector<int> pref(n, inf), suff(n, inf);
    if (m.contains(0))
        pref[0] = m[0];
    if (m.contains(n - 1))
        suff[n - 1] = m[n - 1];

    for (int i = 1; i < n; i++)
    {
        pref[i] = pref[i - 1] + 1;
        if (m.contains(i))
            pref[i] = std::min(pref[i], m[i]);
    }

    for (int i = n - 2; i >= 0; i--)
    {
        suff[i] = suff[i + 1] + 1;
        if (m.contains(i))
            suff[i] = std::min(suff[i], m[i]);
    }

    for (int i = 0; i < n; i++)
        std::cout << std::min(pref[i], suff[i]) << " \n"[i == n - 1];
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