#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);

    int one = 0, zero = 0;

    for (int i = 0; i < n; ++i)  
    {
        std::cin >> a[i];
        one += a[i] == 1;
        zero += a[i] == 0;
    }
    if (one)
        std::cout << one * (1LL << zero) << "\n";
    else
        std::cout << "0\n";
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