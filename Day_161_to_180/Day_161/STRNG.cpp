#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

void solve()
{
    int n;
    std::cin >> n;

    int g = 0;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    std::vector<int> p(n), s(n);
    p[0] = a[0], s.back() = a.back();

    for (int i = 1; i < n; i++)
        p[i] = std::gcd(p[i - 1], a[i]);

    for (int i = n - 2; i >= 0; --i)
        s[i] = std::gcd(s[i + 1], a[i]);

    auto pref = [&](int i)
    {
        if (i - 1 < 0)
            return 0;
        return p[i - 1];
    };

    auto suff = [&](int i)
    {
        if (i + 1 >= n)
            return 0;

        return s[i + 1];
    };

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (std::gcd(pref(i), suff(i)) != 1)
            ans++;
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