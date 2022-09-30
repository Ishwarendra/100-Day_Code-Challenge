#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, q;
    std::cin >> n >> q;

    std::vector<std::pair<int, int>> a(n);
    for (auto &[h, w] : a)
        std::cin >> h >> w;

    std::vector prod(1001, std::vector<i64>(1001));

    for (auto &[h, w] : a)
        prod[h][w] += 1LL * h * w;

    for (int i = 1; i <= 1000; ++i)
    {
        for (int j = 1; j <= 1000; ++j)
            prod[i][j] += prod[i][j - 1] + prod[i - 1][j] - prod[i - 1][j - 1];
    }

    while (q--)  
    {
        int hs, ws, hb, wb;
        std::cin >> hs >> ws >> hb >> wb;
        hb--, wb--;

        std::cout << std::max(0LL, prod[hb][wb] - prod[hs][wb] - prod[hb][ws] + prod[hs][ws]) << "\n";
    }
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