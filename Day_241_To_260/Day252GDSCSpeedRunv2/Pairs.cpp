#include "bits/stdc++.h"

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
    
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::map<int, int> m;
    i64 ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += m[k + a[i]];

        if (a[i] != 0)
            ans += m[-k + a[i]];

        m[a[i]]++;
    }

    std::cout << ans;
    
    return 0;
}