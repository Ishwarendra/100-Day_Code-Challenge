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
    int n;
    std::cin >> n;

    std::vector<int> h(n), a(n - 2);
    for (int i = 0; i < n; ++i)
        std::cin >> h[i];

    for (int i = 1; i < n - 1; i++)
        a[i - 1] = std::max(0, std::max(h[i - 1], h[i + 1]) - h[i] + 1);

    if (n % 2)
    {
        i64 ans = 0;
        for (int i = 0; i < std::size(a); i += 2)
            ans += a[i];

        std::cout << ans << "\n";
    }
    else
    {
        std::vector<i64> dots, cross;

        for (int i = 0; i < std::size(a); ++i)
            (i % 2 ? cross : dots).push_back(a[i]);

        n = std::size(dots);

        for (int i = 1; i < n; i++)
            dots[i] += dots[i - 1];
        for (int i = 1; i < n; i++)
            cross[i] += cross[i - 1];

        i64 ans = std::min(cross.back(), dots.back());
        print(a, dots, cross)
        for (int i = 0; i < n - 1; i++)
        {
            i64 cur_ans = dots[i] + cross.back() - cross[i];
            ans = std::min(ans, cur_ans);
        }

        std::cout << ans << "\n";
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