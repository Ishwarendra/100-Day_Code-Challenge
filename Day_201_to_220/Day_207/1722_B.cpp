#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n = 2, m;
    std::cin >> m;

    std::vector<std::string> a(2);
    for (int i = 0; i < 2; ++i)  
    {
        std::cin >> a[i];

        for (char &ch : a[i])
        {
            if (ch == 'G')
                ch = 'B';
        }
    }

    std::cout << (a[0] == a[1] ? "YES\n" : "NO\n");
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