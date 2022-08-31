#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    for (int i = 0; i < m; ++i)
        std::cin >> b[i];

    std::vector<int> dp((1 << 9) + 1, 0);
    for (int i = 0; i < m; ++i)
        dp[a[0] & b[i]] = 1;

    for (int _ = 1; _ < n; _++)
    {
        std::vector<int> ndp((1 << 9) + 1, 0);

        for (int i = 0; i <= (1 << 9); ++i)
        {
            if (dp[i])
            {
                for (int j = 0; j < m; j++)
                    ndp[i | (a[_] & b[j])] = 1;
            }
        }

        std::swap(dp, ndp);
    }

    for (int i = 0; i <= (1 << 9); i++)
    {
        if (dp[i])
        {
            std::cout << i << "\n";
            return 0;
        }
    }
    
    return 0;
}