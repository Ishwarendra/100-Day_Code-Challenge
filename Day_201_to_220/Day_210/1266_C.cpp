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
    
    int n, m;
    std::cin >> n >> m;   

    if (n == 1 and m == 1) 
    {
        std::cout << "0\n";
        return 0;
    }

    bool rev = false;
    if (m < n)
        rev = true, std::swap(n, m);
    std::vector a(n, std::vector<int>(m));

    for (int i = 0, num = n + m; i < m; i++, num--)
    {
        for (int j = 0; j < n; j++)
            a[j][i] = num;
    }
    
    for (int i = 1, cur = 2; i < n; i++, cur++)
    {
        for (int j = 0; j < m; ++j)
            a[i][j] = (cur / std::gcd(a[i][j], cur)) * a[i][j];
    }

    if (!rev)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
                std::cout << a[i][j] << " \n"[j + 1 == m];
        }
    }
    else    
    {
        for (int j = 0; j < m; ++j)
        {
            for (int i = 0; i < n; ++i)
                std::cout << a[i][j] << " \n"[i + 1 == n];
        }
    }

    return 0;
}