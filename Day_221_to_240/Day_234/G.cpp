#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

void solve()
{
    int n, s;
    std::cin >> n >> s;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)  
        std::cin >> a[i];

    int sum = std::accumulate(a.begin(), a.end(), 0);
    int to_find = s;
    int ans = 0, cur = 0;

    if (sum < s)
    {
        std::cout << "-1\n";
        return;
    }

    if (sum == s)
    {
        std::cout << "0\n";
        return;
    }

    for (int i = 0, j = 0; j < n; j++)
        {
            cur += a[j];
            
            while (i <= j and cur > to_find)
                cur -= a[i++];
            
            if (cur == to_find)
                ans = std::max(ans, j - i + 1);
        } 

    std::cout << n - ans << "\n";
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