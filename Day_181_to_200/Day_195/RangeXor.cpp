#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    for (int i = 1; i < n; i++)
        a[i] ^= a[i - 1];

    while (q--)
    {
        int x, y;
        std::cin >> x >> y;
        x--, y--;

        if (x - 1 >= 0)
            std::cout << (a[y] ^ a[x - 1]) << std::endl;
        else
            std::cout << a[y] << std::endl;
    }
    
    return 0;
}