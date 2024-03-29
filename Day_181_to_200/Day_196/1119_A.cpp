#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;
 
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<int> a(n);

    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] != a[0])
            ans = std::max(ans, i);
        if (a[i] != a[n - 1])
            ans = std::max(ans, n - i - 1);
    }

    std::cout << ans;
    
    return 0;
}