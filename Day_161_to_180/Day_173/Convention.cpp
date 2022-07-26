#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);

    int n, m, c;
    std::cin >> n >> m >> c;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    std::sort(std::begin(a), std::end(a));

    int left = 0, right = a.back();
    int ans = 0;

    auto good = [&](int x)
    {
        int bus_needed = 1;
        int cur_size = 1;
        int first = 0;

        // starting c cows are taken in bus-1
        for (int i = 1; i < n; i++)
        {
            if (cur_size < c and a[i] - a[first] <= x)
                cur_size++;
            else
            {
                bus_needed++;
                cur_size = 1;
                first = i;
            }
        }

        return bus_needed <= m;
    };

    while (left <= right)
    {
        int mid = (left + right + 1) / 2;

        if (good(mid))
            ans = mid, right = mid - 1;
        else
        {
            left = mid + 1;
        }
    }

    std::cout << ans << "\n";
    
    return 0;
}
