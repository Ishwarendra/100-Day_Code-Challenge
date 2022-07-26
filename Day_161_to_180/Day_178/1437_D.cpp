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

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)  
        std::cin >> a[i];

    std::vector<std::vector<int>> sorted;
    sorted.push_back({a[0]});
    sorted.push_back({a[1]});

    for (int i = 2; i < n; ++i)
    {
        if (sorted.back().back() < a[i])
            sorted.back().push_back(a[i]);
        else
            sorted.push_back({a[i]});
    }

    int cnt = std::size(sorted);
    int ans = 1;

    int p = std::size(sorted[0]), c = std::size(sorted[1]);

    for (int i = 2; i < cnt;)
    {
        p = c;
        int numc = c;
        c = 0;

        while (i < cnt and numc--)
            c += std::size(sorted[i++]);

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