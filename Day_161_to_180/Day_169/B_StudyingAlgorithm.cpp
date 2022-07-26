#include <bits/stdc++.h>

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
    
    int x, n;
    std::cin >> n >> x;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    std::sort(std::begin(a), std::end(a));
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum > x)
        {
            std::cout << i << "\n";
            return 0;
        }
    }

    std::cout << n << "\n";
    
    return 0;
}