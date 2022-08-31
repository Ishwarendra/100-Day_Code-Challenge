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
    int a;
    std::string b;

    std::cin >> a >> b;
    int n = std::size(b);

    if (b == std::string(n, '9'))
        std::cout << 1LL * a * n << "\n";
    else
        std::cout << 1LL * a * (n - 1) << "\n";
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