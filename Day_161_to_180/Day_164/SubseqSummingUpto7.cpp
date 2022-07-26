#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
        a[i] %= 7;
    }

    for (int i = 1; i < n; ++i)
        a[i] = (a[i] + a[i - 1]) % 7;

    std::vector<int> first(7, n), last(7, -1);
    for (int i = 0; i < n; ++i)
    {
        first[a[i]] = std::min(first[a[i]], i);
        last[a[i]] = std::max(last[a[i]], i);
    }

    int ans = 0;
    for (int i = 0; i < 7; i++)
    {
        if (first[i] == n)
            continue;

        ans = std::max(ans, last[i] - first[i]);
    }

    std::cout << ans << '\n';
    
    return 0;
}