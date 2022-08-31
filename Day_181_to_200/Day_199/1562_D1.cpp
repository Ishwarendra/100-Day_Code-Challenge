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
    std::string s;
    std::cin >> n >> q >> s;

    std::vector<int> one1(n), one2(n);
    int positive = 1;
    for (int i = 0; i < n; ++i)
    {
        if ((positive and s[i] == '+') or (!positive and s[i] == '-'))
            one1[i] = 1;

        one2[i] += (1 - one1[i]) + (i - 1 >= 0 ? one2[i - 1] : 0);
        one1[i] += (i - 1 >= 0 ? one1[i - 1] : 0);
        positive ^= 1;
    }

    print(one1, one2)
    while (q--)
    {
        int l, r;
        std::cin >> l >> r;
        l--, r--;

        auto f = [&](std::vector<int> &one)
        {
            int o = one[r] - (l - 1 < 0 ? 0 : one[l - 1]);
            int z = r - l + 1 - o;

            if (z - o == 0)
                std::cout << "0\n";
            else if ((r - l + 1) % 2)
                std::cout << "1\n";
            else
                std::cout << "2\n";
        };

        f(l % 2 ? one2 : one1);
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