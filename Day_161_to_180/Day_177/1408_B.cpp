#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)  
        std::cin >> a[i];

    int c = std::size(std::set(std::begin(a), std::end(a)));
    if (c <= k)
    {
        std::cout << "1\n";
        return;
    }   

    if (k > 1)
    {
        std::cout << (c + k - 3) / (k - 1) << "\n";
        return;
    }

    std::cout << "-1\n";
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