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

    auto check = [&](int j)
    {
        int zero = -1, one = -1;
        int no = 0;
        for (int i = 0; i < std::size(a); i++)
        {
            if (a[i][j] == '0')
            {
                if (zero == -1)
                    zero = resp[i];
                else if (zero != resp[i])
                    no |= 1;
            }
            else
            {
                if (one == -1)
                    one = resp[i];
                else if (one != resp[i])
                    no |= 2;
            }
        }

        return no;
    };

    std::vector<int> vis(n);
    int rem = n;
    std::set<int> unmark;
    while (rem > 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (vis[i])
                continue;
            
            vis[i] = 1;
            rem--;

            int no = check(i);
            if (no == 3)
            {
                unmark.emplace(i);
                continue;
            }
            else if (no == 0)
            {
                std::cout << "OK\n";
                return;
            }
            else
            {
                char ch = (no == 1 ? '1' : '0');
                std::vector<std::string> na;
                std::vector<int> nresp;

                for (int j = 0; j < std::size(a); j++)
                {
                    if (a[j][i] == ch)
                        na.emplace_back(a[j]), nresp.emplace_back(resp[j]);
                }

                std::swap(a, na);
                std::swap(resp, nresp);

                while (!unmark.empty())
                {
                    vis[*std::begin(unmark)] = 0;
                    unmark.erase(std::begin(unmark));
                    rem++;
                }
            }
        }
    }

    std::cout << "LIE\n";
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