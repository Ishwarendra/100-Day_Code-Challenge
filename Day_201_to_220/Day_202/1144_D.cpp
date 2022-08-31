#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        m[a[i]]++;
    }

    auto b = a;

    int max;
    int max_freq = 0;
    for (auto [num, f] : m)
    {
        if (f > max_freq)
        {
            max_freq = f;
            max = num;
        }
    }

    std::queue<int> id;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == max)
            id.emplace(i);
    }

    std::vector<std::array<int,3 >> ans;
    while (!id.empty())
    {
        auto cur = id.front();
        id.pop();

        if (cur - 1 >= 0 and a[cur - 1] != max)
        {
            if (a[cur - 1] > max)
                ans.push_back({2, cur, cur + 1});
            else
                ans.push_back({1, cur, cur + 1});

            id.emplace(cur - 1);
            a[cur - 1] = max;
        }

        if (cur + 1 < n and a[cur + 1] != max)
        {
            if (a[cur + 1] > max)
                ans.push_back({2, cur + 2, cur + 1});
            else
                ans.push_back({1, cur + 2, cur + 1});

            id.emplace(cur + 1);   
            a[cur + 1] = max;
        }
    }

    std::cout << std::size(ans) << "\n";
    for (auto [i, j, k] : ans)
        std::cout << i << " " << j << " " << k << "\n";

    for (auto [i, j, k] : ans)
    {
        j--, k--;
        if (i == 1)
            b[j] += std::abs(b[k] - b[j]);
        else 
            b[j] -= std::abs(b[k] - b[j]);
    }

    assert(std::size(std::set(std::begin(b), std::end(b))) == 1);

    return 0;
}