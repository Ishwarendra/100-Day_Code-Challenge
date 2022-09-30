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

    std::vector a(n, std::vector<int>(n));
    std::vector<int> b(n);
    for (int i = 0; i < n; ++i)
        std::cin >> b[i];
    
    int diff = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 1; j < n; ++j)
            a[i][j] = (a[i][j - 1] + diff) % n;

        diff++;
    }

    for (int i = 0; i < n; i++)
    {
        int need = (b[i] - a[i][i] + n) % n;
        for (int j = 0; j < n; ++j)
            a[i][j] = (a[i][j] + need) % n;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; j++)
            std::cout << a[i][j] << " \n"[j == n - 1];
    }

    return 0;
}