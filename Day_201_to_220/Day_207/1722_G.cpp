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

    if (n % 4 == 0)
    {
        for (int i = 0; i < n; ++i)
            std::cout << i << " ";
    }
    else if (n % 4 == 1)
    {
        std::cout << "0 ";
        for (int i = 4; i < n + 3; ++i)
            std::cout << i << " ";
    }
    else if (n % 4 == 2)
    {
        std::cout << "1 " << (1 << 29) << " 2 " << (3 << 28) << " 3 " << (1 << 28) << " ";
        for (int i = 4; i < n - 2; ++i)
            std::cout << i << " ";
    }
    else
    {
        std::cout << "1 2 3 ";
        for (int i = 4; i < n + 1; i++)
            std::cout << i << " ";
    }

    std::cout << "\n";
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