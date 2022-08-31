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
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    std::sort(std::begin(a), std::end(a));
    const int inf = 1e9;

    int ans = inf;

    auto check = [&](int x)
    {
        std::multiset<int> m;
        for (int i = 0; i < n; i++)
        {
            if (a[i] < x)
                continue;

            int cur = a[i];
            int op = 0;
            while (cur > x)
            {
                cur /= 2, op++;
            }

            if (cur == x)
                m.emplace(op);
        }

        if (std::size(m) < k)
            return inf;

        int cnt = 0, op = 0;
        while (cnt < k)
        {
            cnt++;
            op += *std::begin(m);
            m.erase(std::begin(m));
        }

        return op;
    };

    for (int make = 0; make <= a[n - 1]; make++)
        ans = std::min(ans, check(make));

    std::cout << ans << "\n";
    
    return 0;
}