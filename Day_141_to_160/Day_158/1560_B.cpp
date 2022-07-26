#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

void solve()
{
    int a, b, c;
    std::cin >> a >> b >> c;

    int n = abs(b - a) * 2;

    if (a > n or b > n or c > n)
    {
        std::cout << "-1\n";
        return;
    }

    if (c + n / 2 > n and c - n / 2 > 0)
        std::cout << c - n / 2 << "\n";
    else if (c - n / 2 <= 0 and c + n / 2 <= n)
        std::cout << c + n / 2 << "\n";
    else
        std::cout << "-1\n";
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