#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

void solve()
{
    int n, x;
    std::cin >> n >> x;

    n *= 2;
    std::vector<int> h(n);
    for (int i = 0; i < n; ++i)  
        std::cin >> h[i];

    std::sort(std::begin(h), std::end(h));
    for (int i = 0; i < n / 2; ++i)
    {
        if (h[i + n / 2] - h[i] < x)
        {
            std::cout << "NO\n";
            return;
        }
    }

    std::cout << "YES\n";
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