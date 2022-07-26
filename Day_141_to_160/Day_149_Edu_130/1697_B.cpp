#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

void solve()
{
    int n, q;
    std::cin >> n >> q;

    std::vector<long long> a(n + 1);
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    std::sort(a.begin(), a.end());

    for (int i = 1; i <= n; ++i)
        a[i] += a[i - 1];

    while (q--)
    {
        int x, y;
        std::cin >> x >> y;

        std::cout << a[n - x + y] - a[n - x] << "\n";
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;

    while (t--)
        solve();

    return 0;
}