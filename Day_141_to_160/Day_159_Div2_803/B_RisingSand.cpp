#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)  
        std::cin >> a[i];

    if (k == 1)
        std::cout << (n - 1) / 2 << "\n";
    else
    {
        int cnt = 0;
        for (int i = 1; i < n - 1; i++)
        {
            if (a[i] > a[i - 1] + a[i + 1])
                cnt++;
        }

        std::cout << cnt << "\n";
    }
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