#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    i64 x;
    std::cin >> x;

    i64 a = 1;
    for (i64 i = 1; i * i <= x; i++)
    {
        if (x % i == 0 and std::lcm(i, x / i) == x)
            a = i;
    }

    std::cout << a << ' ' << x / a << "\n";
    
    return 0;
}