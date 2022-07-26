#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

void solve()
{
    int n, x;
    std::cin >> n >> x;

    if (n % 2)
    {
        if (x % 2 == 0)
            std::cout << "No\n";
        else if ((n - x) % 2 == 0)
            std::cout << "Yes\n";
        else
            std::cout << "No\n";
    }
    else 
        std::cout << "Yes\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while(t--)
        solve();
    
    return 0;
}