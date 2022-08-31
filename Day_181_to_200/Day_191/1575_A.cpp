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
    
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> a(n);
    std::map<std::string, int> pos;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
        pos[a[i]] = i;
    }

    std::sort(std::begin(a), std::end(a), [&](const std::string &x, std::string &y)
    {
        for (int i = 0; i < n; i++)
        {
            if (x[i] != y[i])
                return (i % 2 ? x[i] > y[i] : x[i] < y[i]); 
        }

        return true;
    });

    for (int i = 0; i < n; ++i)
        std::cout << pos[a[i]] + 1 << " \n"[i + 1 == n];
    
    return 0;
}