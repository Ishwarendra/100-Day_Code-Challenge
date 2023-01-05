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
    
    // std::freopen("factory.in", "r", stdin);
    // std::freopen("factory.out", "w", stdout);

    int n;
    std::cin >> n;

    std::vector outdeg(n, 0);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;

        outdeg[u]++;
    }

    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        if (!outdeg[i])
        {
            if (ans == -1)
                ans = i + 1;
            else
            {
                ans = -1;
                break;
            }
        }
    }

    std::cout << ans;

    return 0;
}
