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
    
    // std::freopen("taming.in", "r", stdin);
    // std::freopen("taming.out", "w", stdout);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    for (int i = n - 1; i >= 1; i--)
    {
        if (a[i] != -1 and a[i - 1] == -1)
            a[i - 1] = a[i] - 1;
        else if (a[i] > 0 and a[i - 1] != a[i] - 1)
        {
            std::cout << "-1\n";
            return 0;
        }
    }

    if (a[0] > 0)
    {
        std::cout << "-1\n";
        return 0;
    }

    a[0] = 0;
    int min = std::count(std::begin(a), std::end(a), 0);
    int max = min;
    int cnt = std::count(std::begin(a), std::end(a), -1);

    std::cout << min << " " << cnt + min;
    
    return 0;
}
