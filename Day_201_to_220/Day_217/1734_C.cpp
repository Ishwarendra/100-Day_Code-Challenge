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
    std::string s;
    std::cin >> n >> s;

    i64 ans = 0;
    for (int i = 1; i <= n; ++i)  
    {
        if (s[i - 1] == '1')
            continue;

        for (int j = i; j <= n; j += i)
        {
            if (s[j - 1] == '1')
                break;
            if (s[j - 1] == '#')
                continue;

            s[j - 1] = '#';
            ans += i;
        }
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