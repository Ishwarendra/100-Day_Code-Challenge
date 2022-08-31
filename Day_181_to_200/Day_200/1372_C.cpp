#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    if (std::is_sorted(std::begin(a), std::end(a)))
        std::cout << "0\n";
    else
    {
        int i = 0; 
        bool can = true;
        for (i = 0; i < n; i++)
        {
            if (a[i] == i + 1)
                continue;
            else
                break;
        }

        int j = n - 1;
        for (; j > i; j--)
        {
            if (a[j] == j + 1)
                continue;
            else
                break;
        }

        for (int p = i; p <= j; p++)
        {
            if (p + 1 == a[p])
                can = false;
        }

        std::cout << (can ? "1\n" : "2\n");
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