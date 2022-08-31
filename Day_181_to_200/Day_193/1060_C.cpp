#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 2e9 + 1; 

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    for (int i = 0; i < m; ++i)
        std::cin >> b[i];

    int x;
    std::cin >> x;

    for (int i = 1; i < n; i++)
        a[i] += a[i - 1];
    for (int i = 1; i < m; i++)
        b[i] += b[i - 1];

    auto f = [&](std::vector<int> &x)
    {
        std::vector<int> lenx(std::size(x), inf);

        for (int i = 0; i < std::size(x); i++)
        {
            for (int j = i; j < std::size(x); j++)
                lenx[j - i] = std::min(lenx[j - i], x[j] - (i - 1 < 0 ? 0 : x[i - 1]));
        }

        return lenx;
    };

    auto lena = f(a);
    auto lenb = f(b);

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; ++j)
        {
            if (1LL * lena[i] * lenb[j] <= x)
                ans = std::max(ans, (i + 1) * (j + 1));
        }

    std::cout << ans << "\n";
    
    return 0;
}