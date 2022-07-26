#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

void solve()
{
    int n;
    std::cin >> n;

    std::map<int, std::vector<int>> m;
    for (int i = 0; i < n; ++i)
    {
        int x;
        std::cin >> x;

        m[x].push_back(i);
    }

    std::map<int, std::vector<int>> anss;

    for (auto &p : m)
    {
        int ans = 0;
        int cur = 1;
        int mxl = p.second[0], mxr = p.second[0], l = p.second[0];

        for (int i = 1; i < p.second.size(); i++)
        {
            if (p.second[i - 1] + 1 == p.second[i])
                cur++;
            else
            {
                cur -= p.second[i] - p.second[i - 1] - 2;
                if (cur <= 0)
                {
                    l = p.second[i];
                    cur = 1;
                }
            }

            if (cur > ans)
            {
                ans = cur, mxl = l, mxr = p.second[i];
            }
        }

        anss[p.first] = {ans, mxl, mxr};
    }

    int best = -1;

    for (auto &p : anss)
    {
        if (anss[p.first] > anss[best])
            best = p.first;
    }

    std::cout << best << " " << anss[best][1] + 1 <<
              " " << anss[best][2] + 1 << "\n";
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