#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<i64> a(n);
    std::vector<int> mod[m];

    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
        mod[a[i] % m].push_back(i);
    }

    int k = n / m;
    std::vector<std::pair<int, int>> decrease;
    i64 operations = 0;

    for (int i = 0; i < 2 * m; i++)
    {
        int cur = i % m;

        while (std::size(mod[cur]) > k)
        {
            decrease.emplace_back(mod[cur].back(), cur);
            mod[cur].pop_back();
        }

        while (std::size(mod[cur]) < k and !decrease.empty())
        {
            // last few elements of decrease are the best choice to change
            auto p = decrease.back();
            decrease.pop_back();

            // 8 -> 0 => 0 - 8 % m = -8 % m | to - from
            int inc = (cur - p.second + m) % m;
            operations += inc;
            a[p.first] += inc;
            mod[cur].push_back(p.second);
        }
    }

    std::cout << operations << "\n";
    for (int i = 0; i < n; ++i)
        std::cout << a[i] << " \n"[i == n - 1];

    return 0;
}