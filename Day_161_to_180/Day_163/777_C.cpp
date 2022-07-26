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
    
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            std::cin >> a[i][j];
    }

    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 1)); // col, start_row
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n - 1; ++i)
        {
            int pos = i;
            while (pos < n - 1 and a[pos][j] <= a[pos + 1][j])
                pos++;

            dp[j][i] = pos - i + 1;

            int cnt = 1;
            while (pos >= i)
                dp[j][pos--] = cnt++;  

            i += dp[j][i] - 1;
        }
    }

    std::vector<int> max(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; ++j)
            max[i] = std::max(max[i], dp[j][i]);
    }
    
    int q;
    std::cin >> q;

    while (q--)
    {
        int l, r;
        std::cin >> l >> r;

        l--, r--;
        int len = r - l + 1;
        if (max[l] >= len)
            std::cout << "Yes\n";
        else
            std::cout << "No\n";
    }
    
    return 0;
}