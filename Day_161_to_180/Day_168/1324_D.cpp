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

    for (int i = 0; i < n; ++i)
    {
        int x;
        std::cin >> x;

        a[i] -= x;
    }

    std::sort(std::begin(a), std::end(a));

    i64 cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        auto it = std::upper_bound(std::begin(a), std::end(a), -a[i]);
        if (a[i] <= 0)
            // cnt += n - (it - std::begin(a)); // problem here
            continue;
        else
            cnt += i - (it - std::begin(a));
    }

    std::cout << cnt << "\n";
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