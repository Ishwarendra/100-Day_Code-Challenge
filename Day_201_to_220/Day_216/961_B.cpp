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

    std::vector<int> a(n), t(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    for (int i = 0; i < n; ++i)
        std::cin >> t[i];

    i64 sum = 0;
    for (int i = 0; i < n; ++i)
    {
        if (t[i])
        {
            sum += a[i];
            a[i] = 0;
        }
    }

    i64 max_sum = 0;
    i64 cur_sum = 0;
    for (int i = 0; i < k - 1; i++)
        cur_sum += a[i];

    for (int i = k - 1; i < n; i++)
    {
        cur_sum += a[i];
        max_sum = std::max(max_sum, cur_sum);
        cur_sum -= a[i - k + 1];
    }
        
    std::cout << max_sum + sum << "\n";

    return 0;
}