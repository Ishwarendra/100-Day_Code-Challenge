#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);

    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<std::string> a(n);

    for (int i = 0; i < n; ++i)    
        std::cin >> a[i];

    std::vector<std::string> ans;

    for (int i = 0; i < n; ++i)
    {
        std::string s;

        for (int j = 0; j < m; ++j)
        {
            for (int id = 0; id < k; ++id)
                s += a[i][j];
        }

        for (int j = 0; j < k; ++j)
            ans.push_back(s);
    }

    for (auto &s : ans)
        std::cout << s << "\n";
    
    return 0;
}