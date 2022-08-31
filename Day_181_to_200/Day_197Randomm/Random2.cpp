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
    
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    for (int i = 0; i < m; ++i)
        std::cin >> b[i];

    std::sort(std::begin(a), std::end(a));
    for (int i = 0; i < m; ++i)
    {
        auto id = std::upper_bound(std::begin(a), std::end(a), b[i]) - std::begin(a);
        b[i] = id;
    }

    for (int i = 0; i < m; ++i)
        std::cout << b[i] << " \n"[i == m - 1];
    
    return 0;
}