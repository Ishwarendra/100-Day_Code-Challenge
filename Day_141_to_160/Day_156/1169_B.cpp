#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::set<int>> a(m);
    for (int i = 0; i < m; ++i) 
    {
        int p1, p2;
        std::cin >> p1 >> p2;
        a[i].emplace(p1);
        a[i].emplace(p2);
    }

    auto check = [&](int x, int y)
    {
        for (int i = 0; i < m; ++i)
        {
            print(a[i], x, y)
            if (!a[i].count(x) and !a[i].count(y))
                return false;
        }

        return true;
    };

    for (int x : a[0])
    {
        std::vector<int> y;
        for (int i = 0; i < m; i++)
        {
            if (!a[i].count(x))
            {
                for (int p : a[i])
                    y.emplace_back(p);

                break;
            }
        }

        if (y.empty())
        {
            std::cout << "YES\n";
            return;
        }

        for (int y_ : y)
        {
            if (check(x, y_))
            {
                std::cout << "YES\n";
                return;
            }
        }
    }

    std::cout << "NO\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    
    while (t--)
        solve();
    
    return 0;
}