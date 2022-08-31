#include <bits/stdc++.h>

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

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    std::vector<std::array<int, 2>> b(m);
    int limit = 0;

    for (auto &[x, y] : b)
    {
        std::cin >> y >> x;
        if (limit <= n)
            limit += y;
    }

    std::sort(std::begin(a), std::end(a));
    std::sort(std::begin(b), std::end(b), std::greater());

    for (int i = 0, j = 0; i < std::min(limit, n); j++)
    {
        auto [num, f] = b[j];
        for (int k = 0; k < f and i < std::min(limit, n); k++, i++)
            a[i] = std::max(a[i], num);
    }

    i64 sum = std::accumulate(std::begin(a), std::end(a), 0LL);
    std::cout << sum << "\n";
    
    return 0;
}