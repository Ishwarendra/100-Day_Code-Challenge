#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);

    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    std::sort(std::begin(a), std::end(a));

    while (q--)
    {
        int x, y;
        std::cin >> x >> y;

        auto it1 = std::lower_bound(std::begin(a), std::end(a), x);
        auto it2 = std::upper_bound(std::begin(a), std::end(a), y);

        if (it2 - it1 < 0)
            std::cout << "0\n";
        else
            std::cout << (it2 - it1) << "\n";
    }
    
    return 0;
}
