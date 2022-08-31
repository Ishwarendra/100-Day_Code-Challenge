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
    
    int n, q;
    std::cin >> n >> q;

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector<std::pair<i64, i64>> ans(n - 1);
    std::vector<i64> b(n);

    ans[0] = std::pair<int, int>(a[0], a[1]);
    for (int i = 1; i < n - 1; i++)
        ans[i] = {std::max(ans[i - 1].first, ans[i - 1].second), a[i + 1]};

    int max_id = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > a[max_id])
            max_id = i;
    }
    int pos = 0;
    for (int i = max_id; i < n; i++)
        b[pos++] = a[i];

    for (int i = 1; i <= max_id; i++)
    {
        if (a[i - 1] > a[i])
            std::swap(a[i], a[i - 1]);
        b[pos++] = a[i - 1];
    }

    a = b;

    while (q--)
    {
        i64 m;
        std::cin >> m;
        m--;

        if (m < max_id)
            std::cout << ans[m].first << " " << ans[m].second << "\n";
        else
        {
            m -= max_id;
            m = 1 + m % (n - 1);

            std::cout << a[0] << " " << a[m] << "\n";
        }
    }
    
    return 0;
}