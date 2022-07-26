#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<int> c(n);
    for (int i = 0; i < n; ++i)  
        std::cin >> c[i];

    int sum = std::accumulate(std::begin(c), std::end(c), 0);
    std::cout << sum % m << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    for (int i = 1; i <= t; i++)
    {
        std::cout << "Case #" << i << ": ";
        solve();
    }
    
    return 0;
}