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
    
    int m, n, k, t;
    std::cin >> m >> n >> k >> t;

    std::vector<int> a(m);
    for (int i = 0; i < m; ++i)
        std::cin >> a[i];

    std::map<int, std::vector<std::pair<int, int>>> traps;
    for (int i = 0; i < k; i++)
    {
        int l, r, d;
        std::cin >> l >> r >> d;

        traps[l].emplace_back(r, d);
    }

    std:sort(std::begin(a), std::end(a), std::greater());

    auto good = [&](int people)
    {
        int lowest = a[people];
        int disarm = 0;
        i64 tme = 0;

        for (auto &[l, p] : traps)
        {
            for (auto &[r, d] : p)
            {
                if (d <= lowest)
                    continue;

                tme += 2LL * std::max(0, r - std::max(disarm, l - 1));
                disarm = std::max(disarm, r);
            }
        }

        return n + 1 + tme <= i64(t);
    };

    int left = 0, right = m - 1, ans = -1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (good(mid))
            ans = mid, left = mid + 1;
        else
            right = mid - 1;
    }

    std::cout << ans + 1 << "\n";
    
    return 0;
}