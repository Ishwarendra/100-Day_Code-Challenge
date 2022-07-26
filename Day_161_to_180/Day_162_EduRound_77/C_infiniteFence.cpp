#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    i64 r, b, k;
    std::cin >> r >> b >> k;

    i64 g = std::gcd(r, b);
    r /= g, b /= g;

    if (r > b)  
        std::swap(r, b);

    int x = (b - 1 + r - 1) / r;
    
    if (x >= k)
        std::cout << "REBEL\n";
    else
        std::cout << "OBEY\n";
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