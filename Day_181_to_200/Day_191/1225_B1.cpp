#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k, d;
    std::cin >> n >> k >> d;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)  
        std::cin >> a[i];

    std::map<int, int> m;

    for (int i = 0; i < d - 1; i++)
        m[a[i]]++;

    int ans = k;
    for (int i = d - 1; i < n; i++)
    {
        m[a[i]]++;
        ans = std::min(ans, (int)std::size(m));
        m[a[i - d + 1]]--;

        if (m[a[i - d + 1]] == 0)
            m.erase(a[i - d + 1]);
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