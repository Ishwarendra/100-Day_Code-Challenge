#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        a[i] %= k;
    }

    std::multiset<int> m(std::begin(a), std::end(a));
    int ans = 0;
    while (m.size() > 1)
    {
        int cur = *std::begin(m);
        m.erase(std::begin(m));

        auto it = m.find((k - cur) % k);
        if (it != std::end(m))
        {
            m.erase(it);
            ans += 2;
        }
    }

    std::cout << ans;
    
    return 0;
}