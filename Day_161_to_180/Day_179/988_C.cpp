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
    
    int k;
    std::cin >> k;

    std::vector<std::vector<int>> a(k);
    std::map<i64, std::vector<std::pair<int, int>>> vis;

    for (int i = 0; i < k; ++i)
    {
        int n;
        std::cin >> n;

        std::map<i64, int> cant;

        a[i].resize(n);
        for (int j = 0; j <n; j++)
            std::cin >> a[i][j];

        i64 sum = std::accumulate(std::begin(a[i]), std::end(a[i]), 0LL);

        for (int j = 0; j < n; ++j)
        {
            if (!cant[a[i][j]])
                vis[sum - a[i][j]].emplace_back(i, j);
            cant[a[i][j]] = 1;
        }
    }

    for (auto [sum, p] : vis)
    {
        if (std::size(p) >= 2)
        {
            std::cout << "YES\n";
            std::cout << p[0].first + 1 << " " << p[0].second + 1 << "\n";
            std::cout << p[1].first + 1 << " " << p[1].second + 1 << "\n";

            return 0;
        }
    }

    std::cout << "NO\n";
    
    return 0;
}