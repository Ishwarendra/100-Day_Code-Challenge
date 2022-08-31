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
    
    int n, x;
    std::cin >> n >> x;

    auto complement = [&](int a)
    {
        int b = 0;
        for (int i = 0; i < n; ++i)
        {
            if ((a >> i) & 1)
                continue;

            b |= (1 << i);
        }

        return b;
    };

    if ((n + 1) & n)
    {

    }
    else
    {
        for (int i = 0; i < n; i++)
            std::cout << 
    }
    
    return 0;
}