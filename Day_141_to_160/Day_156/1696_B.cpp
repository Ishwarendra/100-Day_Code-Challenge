#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

void solve()
{
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> a;
    std::vector<int> temp;

    for (int i = 0; i < n; ++i)  
    {
        int x;
        std::cin >> x;

        if (x == 0)
        {
            if (std::size(temp))
                a.push_back(temp), temp.clear();
        }
        else
            temp.push_back(x);
    }

    if (std::size(temp))
        a.push_back(temp);

    int ans = std::size(a);
    ans = std::min(ans, 2);

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