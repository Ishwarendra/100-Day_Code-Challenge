#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

void solve()
{
    int n;
    std::cin >> n;

    std::vector<std::string> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    constexpr int inf = 1e9;
    std::vector<int> vis(n);

    auto f = [&](int r, int row = true)
    {
        if (row)
        {
            int o = std::count(std::begin(a[r]), std::end(a[r]), 'O');
            int cross = std::count(std::begin(a[r]), std::end(a[r]), 'X');

            if (o)
                return inf;

            if (n - cross == 1)
            {
                int can = true;
                for (int i = 0; i < n; i++)
                {
                    if (a[r][i] == '.')
                    {
                        for (int j = 0; j < n; j++)
                        {
                            if (j == r)
                                continue;

                            if (a[j][i] != 'X')
                            {      
                                can = false;
                                break;
                            }
                        }

                        if (can)
                            vis[i] = 1;
                        break;
                    }
                }
            }

            return n - cross;
        }
        else if (!vis[r])
        {
            int ans = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i][r] == 'O')
                    return inf;

                ans += a[i][r] != 'X';
            }

            return ans;
        }

        return inf;
    };

    std::map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int op = f(i);
        if (op != inf)
            m[op]++;
    }

    for (int i = 0; i < n; i++)
    {
        int op = f(i, false);
        if (op != inf)
            m[op]++;
    }

    for (auto [num, f] : m)
    {
        std::cout << num << " " << f << "\n";
        return;
    }

    std::cout << "Impossible\n";
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