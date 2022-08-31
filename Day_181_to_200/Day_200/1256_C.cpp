#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, d;
    std::cin >> n >> m >> d;

    std::vector<int> a(m);
    for (int i = 0; i < m; ++i)
        std::cin >> a[i];

    std::vector<int> suff(m + 1);
    suff[m - 1] = a[m - 1];
    for (int i = m - 2; i >= 0; i--)
        suff[i] += suff[i + 1] + a[i];

    int start = 0;
    std::vector<int> ans(n + 1);

    for (int i = 0; i < m; ++i)
    {
        // start to start + a[i];
        int step = 0;
        while (step < d and suff[i + 1] <= n - (start + step + a[i])) 
            step++;
        step--;

        for (int j = start + step; j < start + step + a[i]; j++)
            ans[j] = i + 1;
        
        start += step + a[i];
    }

    for (int i = n - 1; i > n - 1 - d; i--)
    {
        if (ans[i] != 0)
        {
            std::cout << "YES\n";
            for (int p = 0; p + 1 < std::size(ans); p++)
                std::cout << ans[p] << " ";
            std::cout << "\n";

            return 0;
        }
    }

    std::cout << "NO\n";
    
    return 0;
} 