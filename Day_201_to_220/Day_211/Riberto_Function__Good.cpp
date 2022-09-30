#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    i64 a, b, c, x, k;
    std::cin >> a >> b >> c >> x >> k;

    std::function<i64(i64)> f = [&](i64 k)
    {
        if (k == 0)
            return x;

        a = a % c;
        b %= c;
        x %= c;

        i64 ans = std::abs(a * x + b);
        ans = ans %= c;

        x = ans;
        k--;

        return f(k);
    };  

    std::cout << f(k) << "\n";
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