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

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::map<int, i64> m;
    std::vector<int> p2;

    for (int i = 0; i < 31; ++i)
        p2.push_back((1 << i));

    i64 cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < std::size(p2); j++)
        {
            if (m.contains(p2[j] - a[i]))
                cnt += m[p2[j] - a[i]];
        }

        m[a[i]]++;
    }

    std::cout << cnt;

    return 0;
}