#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    std::vector<int> a(3);
    int ans = 0;
    for (int i = 0; i < 3; i++)  
    {
        std::cin >> a[i];
        if (a[i])
            ans++, a[i]--;
    }

    std::sort(std::rbegin(a), std::rend(a));
    for (int i = 0; i < 3; ++i)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (a[i] > 0 and a[j] > 0)
                a[i]--, a[j]--, ans++;
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