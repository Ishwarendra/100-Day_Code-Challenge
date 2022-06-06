#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(...) 1;
#define print(...) 1;
#endif

constexpr int N = 100;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(N + 2), b(N + 2);

    int l = 0;

    for (int i = 0; i < n; ++i)    
    {
        int r, s;
        std::cin >> r >> s;

        a[l] += s;
        l += r;
        a[l] -= s;
    }

    l = 0;

    for (int i = 0; i < m; ++i)
    {
        int r, s;
        std::cin >> r >> s;

        b[l] += s;
        l += r;
        b[l] -= s;
    }

    for (int i = 0; i < N + 1; ++i)
        a[i + 1] += a[i], b[i + 1] += b[i]; 

    int ans = 0;

    for (int i = 0; i < 100; ++i)
        ans = std::max(ans, b[i] - a[i]);

    std::cout << ans << "\n";

    return 0;
}