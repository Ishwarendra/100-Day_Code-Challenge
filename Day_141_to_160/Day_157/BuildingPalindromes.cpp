#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

void solve()
{
    int n, q;
    std::cin >> n >> q;

    std::string s;
    std::cin >> s;

    std::vector<std::vector<int>> a(26, std::vector<int>(n));
    for (int i = 0; i < n; ++i)
        a[s[i] - 'A'][i]++;

    for (int i = 0; i < 26; ++i)
        for (int j = 1; j < n; ++j)
            a[i][j] += a[i][j - 1];

    int ans = 0;
    while (q--)
    {
        int l, r;
        std::cin >> l >> r;
        l--, r--;

        int odd = 0, even = 0;
        for (int i = 0; i < 26; ++i)
        {
            odd += (a[i][r] - (l - 1 >= 0 ? a[i][l - 1] : 0)) % 2;
            even += (a[i][r] - (l - 1 >= 0 ? a[i][l - 1] : 0)) % 2 == 0;
        }

        ans += odd <= 1;
    }  

    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    for (int i = 1; i <= t; i++)
    {
        std::cout << "Case #" << i << ": ";
        solve();
    }
    
    return 0;
}