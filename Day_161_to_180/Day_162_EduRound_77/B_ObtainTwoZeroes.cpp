#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

void solve()
{
    int a, b;
    std::cin >> a >> b;

    long long e = -1, o = -1;

    if ((2LL * a - b >= 0) and (2LL * a - b) % 3 == 0)
        e = (2LL * a - b) / 3;

    if (((2LL * b - a) >= 0) and (2LL * b - a) % 3 == 0)
        o = (2LL * b - a) / 3;

    if (e == -1 or o == -1) 
        std::cout << "NO\n";
    else
        std::cout << "YES\n";
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