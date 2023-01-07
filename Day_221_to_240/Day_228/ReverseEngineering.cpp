#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> a(m);
    std::vector<int> resp(m);
    for (int i = 0; i < m; i++)
        std::cin >> a[i] >> resp[i];

    auto separable = [&](int j, std::vector<std::string> &b, std::vector<int> &r)
    {
        int zero = -1, one = -1;
        int no = 0;
        for (int i = 0; i < std::size(b); i++)
        {
            if (b[i][j] == '0')
            {
                if (zero == -1)
                    zero = r[i];
                else if (r[i] != zero)
                    no |= 1;
            }
            else
            {
                if (one == -1)
                    one = r[i];
                else if (r[i] != one)
                    no |= 2;
            }
        }

        return no;
    };

    std::vector<int> vis(n);
    auto b = a; 
    auto r = resp;

    int rem = n;
    while (rem > 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (vis[i])
                continue;

            int check = separable(i, b, r);
            vis[i] = 1;
            rem--;

            if (check == 3)    
            {
                std::cout << "LIE\n";
                return;
            }
            else if (check == 0)
            {
                std::cout << "OK\n";
                return;
            }
            else 
            {
                char ch = (check == 1 ? '0' : '1');
                std::vector<std::string> c;
                std::vector<int> d;

                for (int j = 0; j < std::size(b); j++)
                {
                    if (b[j][i] == ch)
                        c.emplace_back(b[j]), d.emplace_back(resp[j]);
                }

                std::swap(b, c);
                std::swap(d, r);
            }
        }
    }

    std::cout << (b.empty() ? "OK\n" : "LIE\n");
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