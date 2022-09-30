#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    i64 n;
    std::cin >> n;

    auto fair = [&](i64 x)
    {        
        auto s = std::to_string(x);
        for (auto ch : s)
        {
            int mod = ch - '0';
            if (mod != 0 and x % mod)
                return false;
        }

        return true;
    };

    int MAX = 1;
    for (int i = 1; i <= 9; ++i)
        MAX = std::lcm(MAX, i);

    for (int i = 0; i <= MAX; ++i)
    {
        if (fair(n + i))
        {
            std::cout << n + i << "\n";
            return;
        }
    }

    std::cout << "baka\n";
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