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

    std::vector<int> a(102);  
    for (int i = 0; i < n; ++i)
    {
        int x;
        std::cin >> x;
        a[x]++;
    }

    int ans = 0;
    bool cant = false;
    
    for (int i = 0; i <= 101; i++)
    {
        if (a[i] == 0)
            break;
        else if (a[i] == 1 or cant)
            ans++, cant = true;
        else 
            ans += 2;
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