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
    
    i64 n;
    std::cin >> n;

    auto pf = [&](i64 x)
    {
        std::map<int, int> m;
        for (i64 i = 2; i * i <= x; i++)
        {
            while (x % i == 0)
                m[i]++, x /= i;
        }

        if (x > 1)
            m[x]++;

        return m;
    };

    auto m = pf(n);
    auto binary_search = [&](int f)
    {
        int left = 0, right = f;
        int ans = 0;

        while (left <= right)
        {
            int mid = (left + right) >> 1;

            if (1LL * mid * mid + mid - 2LL * f <= 0)
                ans = mid, left = mid + 1;
            else 
                right = mid - 1;
        }

        return ans;
    };

    int ans = 0;
    for (auto [num, f] : m)
        ans += binary_search(f);

    std::cout << ans;
    
    return 0;
}