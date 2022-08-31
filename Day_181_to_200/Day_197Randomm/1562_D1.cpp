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

    std::vector<int> a(n, 1), b(n);
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '-')
            a[i] = 0;

        b[i] = 1 - a[i];
    }

    for (int i = 1; i < n; i++)
        a[i] += a[i - 1];
    for (int i = 1; i < n; i++)
        b[i] += b[i - 1];

    while (q--)
    {
        int l, r;
        std::cin >> l >> r;
        l--, r--;

        int sum = 0;
        for (int i = l; i <= r; i++)
        {
            if (s[i] == '+')
                sum += (i - l) % 2 ? -1 : 1;
            else
                sum += (i - l) % 2 ? 1 : -1;
        }
        // if (l % 2)
        //     sum = a[r] - (l - 1 < 0 ? 0 : a[l - 1]);
        // else 
        //     sum = b[r] - (l - 1 < 0 ? 0 : b[l - 1]);

        // print(s.substr(l, r - l + 1), l, r, sum)
        if (sum == 0)
            std::cout << "0\n";
        else if (sum & 1)
            std::cout << "1\n";
        else
            std::cout << "2\n";
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