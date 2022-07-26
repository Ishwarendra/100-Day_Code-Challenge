#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(...) 1;
#define print(...) 1;
#endif

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    auto s = std::string(m, 'B');

    for (int i = 0; i < n; ++i)
    {
        int c1 = a[i] - 1;
        int c2 = m - a[i];

        if (c1 > c2)
            std::swap(c1, c2);

        if (s[c1] == 'B')
            s[c1] = 'A';
        else
            s[c2] = 'A';
    }

    std::cout << s << "\n";
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