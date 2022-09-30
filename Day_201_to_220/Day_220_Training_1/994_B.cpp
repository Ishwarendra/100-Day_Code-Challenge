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

    std::vector<int> p(n);
    std::vector a(n, std::array<int, 3>{});

    for (int i = 0; i < n; i++)
        std::cin >> p[i];
    for (int i = 0; i < n; i++)
    {
        int c;
        std::cin >> c;

       a[i] = {p[i], c, i};
    }

    std::sort(std::begin(a), std::end(a));

    std::multiset<int, std::greater<>> best;
    std::vector<i64> ans(n);

    for (int i = 0; i < n; i++)
    {
        auto it = std::begin(best);
        int cnt = 0;
        ans[a[i][2]] += a[i][1];

        while (cnt < k and it != std::end(best))
        {
            ans[a[i][2]] += *it;            
            it = std::next(it);
            cnt++;
        }

        best.emplace(a[i][1]);
    }

    for (int i = 0; i < n; ++i)
        std::cout << ans[i] << " \n"[i == n - 1];
    
    return 0;
}