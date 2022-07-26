#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)  
        std::cin >> a[i];

    int i = 0, j = 0, ans = 0;

    while (i < n - 1 and j < n - 1)
    {
        while (j < i and j < n - 1)
            j++;

        if (a[i] == 0)
        {
            i++;
            continue;
        }
        if (a[j] != 0)
        {
            j++;
            continue;
        }

        a[i]--;
        a[j]++;
        j++;
        ans++;
    }

    // print(a, ans)
    std::cout << ans + std::accumulate(std::begin(a), std::end(a) - 1, 0LL) << "\n";
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