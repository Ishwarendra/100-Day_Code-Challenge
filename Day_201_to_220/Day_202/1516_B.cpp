#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    if (n == 2)
    {
        std::cout << (a[0] == a[1] ? "YES\n" : "NO\n");
        return;
    }

    int prefxor = 0;
    for (int i = 0; i < n; i++)
        prefxor ^= a[i];

    if (prefxor == 0)
        std::cout << "YES\n";
    else
    {
        int cnt = 0;

        for (int i = 0; i < n;)
        {
            int j = i;
            int xr = 0;
            while (j < n and xr != prefxor)
                xr ^= a[j++];

            if (xr == prefxor)
                cnt++;

            i = j;
        }

        std::cout << (cnt >= 3 ? "YES\n" : "NO\n");
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