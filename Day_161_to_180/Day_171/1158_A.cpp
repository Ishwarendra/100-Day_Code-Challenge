#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
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

    std::vector<int> b(n), g(m);
    for (int i = 0; i < n; ++i)
        std::cin >> b[i];

    for (int i = 0; i < m; ++i)
        std::cin >> g[i];

    std::sort(std::begin(b), std::end(b), std::greater<int>());
    std::sort(std::begin(g), std::end(g), std::greater<int>());

    if (b[0] > g.back())
    {
        std::cout << "-1\n";
        return 0;
    }

    i64 ans = 0;
    for (int i = 0; i < n; i++)
        ans += 1LL * b[i] * m;

    for (int i = 0; i < m - 1; i++)
        ans += g[i] - b[0];

    if (g[m - 1] != b[0])
        ans += g[m - 1] - b[1];

    std::cout << ans;
    
    return 0;
}