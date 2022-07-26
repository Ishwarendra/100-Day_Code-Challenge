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

    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);

    int n;
    std::cin >> n;

    std::map<std::string, int> id;
    id["Mildred"] = 0;
    id["Elsie"] = 1;
    id["Bessie"] = 2;

    std::map<int, std::vector<std::pair<int, int>>> m;

    for (int i = 0; i < n; ++i)
    {
        int day, inc;
        std::string name;

        std::cin >> day >> name >> inc;
        m[day].push_back({id[name], inc});
    }

    std::vector<int> measure(3);
    std::vector<bool> top(3), prev(3, 1);

    for (int i = 0; i < 3; ++i)
        measure[i] = 7;

    int cnt = 0;
    for (auto [day, list] : m)
    {
        for (auto p : list)
        {
            auto [id, inc] = p;
            measure[id] += inc;
        }

        auto max = std::max({measure[0], measure[1], measure[2]});
        for (int i = 0; i < 3; i++)
            top[i] = (measure[i] == max);

        if (top != prev)
            cnt++;

        std::swap(top, prev);
    }

    std::cout << cnt << "\n";

    return 0;
}