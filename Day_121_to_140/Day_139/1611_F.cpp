#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, s;
    std::cin >> n >> s;

    std::vector<i64> a(n);

    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    i64 sum = 0;
    int ans = 0;
    int l = -1, r = -1;

    for (int i = 0, j = 0; i < n; i++)    
    {
        while (sum + a[j] + s >= 0 and j < n)
            sum += a[j], j++;

        if (ans < j - i and sum + s >= 0)
            ans = j - i, l = i, r = j - 1;

        sum -= a[i];
    }

    if (l == -1)
        std::cout << "-1\n";
    else
        std::cout << l + 1 << " " << r + 1 << "\n";
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