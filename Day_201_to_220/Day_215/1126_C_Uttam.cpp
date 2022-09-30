#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    char prev = '(';
    int ans = 0;
    for (int i = 0; i < 2 * n; ++i)
    {
        char ch;
        std::cin >> ch;

        if (prev == '(' and ch == '(')
            ans++;

        prev = ch;
    }

    std::cout << ans << "\n";
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