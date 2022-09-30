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

    std::map<std::string, int> m;
    std::vector a(3, std::vector<std::string>(n));
    for (int i = 0; i < 3; ++i)  
    {
        for (int j = 0; j < n; ++j)
        {
            std::cin >> a[i][j];
            m[a[i][j]]++;
        }
    }

    std::vector<int> points(3);

    for (int i = 0; i < 3; i++)
    {
        auto names = a[i];
        for (auto &name : names)
        {
            if (m[name] == 2)
                points[i]++;
            else if (m[name] == 1)
                points[i] += 3;
        }
    }

    for (int i = 0; i < 3; ++i)
        std::cout << points[i] << " \n"[i == 2];
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