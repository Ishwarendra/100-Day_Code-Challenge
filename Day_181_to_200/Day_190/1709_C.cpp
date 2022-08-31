#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    std::string s;
    std::cin >> s;

    int n = std::size(s);
    int bal = 0, quest = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            bal++;
        else if (s[i] == ')')
            bal--;
        else
            quest++;

        if (bal + quest == 1)
            quest = 0, bal = 1;
    }

    if (abs(bal) == quest)
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
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