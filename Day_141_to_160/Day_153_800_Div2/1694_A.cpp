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

    std::string ans;

    int creepy = abs(b - a);

    if (creepy == 0)
    {
        for (int i = 0; i < a; i++)
            std::cout << "01";
        std::cout << "\n";
        return;
    }

    char more = (a > b ? '0' : '1');
    char less = (a <= b ? '0' : '1');

    int used = 0, used_l = 0;

    for (int i = 0; i < (a + b);)  
    {
        int cnt = 0;
        while (cnt < creepy and used < std::max(a, b))
            ans += more, cnt++, used++, i++;
        
        creepy = 1;
        if (used_l >= std::min(a, b))
            continue;

        ans += less;
        used_l++;
        i++;
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