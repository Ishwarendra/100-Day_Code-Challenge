#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<i64> a(n);
    for (int i = 0; i < n; ++i)      
        std::cin >> a[i];

    for (int i = 1; i < n; ++i) 
        a[i] += a[i - 1];

    i64 ans = 0;
    auto get = [&](int i, int j) -> i64
    {
        if (i < 0 and j < 0 or j < i)
            return 0;
        if (i < 0)
            return a[j];
        if (j < 0)
            return 0;

        if (i == 0)
            return a[j];

        return a[j] - a[i - 1];
    };

    if (k > n)
    {
        i64 sum = 1LL * n * (2LL * k - n - 1) / 2;
        sum += a[n - 1];
        ans = std::max(ans, sum);
    }
    else
    {
        for (int i = 0; i <= n - k; ++i)
        {
            i64 sum = 1LL * k * (k - 1) / 2;
            sum += a[i + k - 1] - (i - 1 >= 0 ? a[i - 1] : 0LL);
            ans = std::max(sum, ans);
            print(i, sum, i + k)
        }
    }

    std::cout << ans << "\n";
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