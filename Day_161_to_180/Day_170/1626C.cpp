#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> k(n), h(n);
    for (int i = 0; i < n; ++i)
        std::cin >> k[i];
    for (int i = 0; i < n; ++i)
        std::cin >> h[i];

    std::vector<std::pair<int, int>> range;

    for (int i = 0; i < n; i++)
        range.emplace_back(k[i] - h[i] + 1, k[i]);

    std::sort(std::begin(range), std::end(range));
    std::vector<std::pair<int, int>> merged;

    auto intersect = [&](int st1, int en1, int st2, int en2)
    {
        return (std::min(st1, st2) <= std::max(st1, st2) and std::max(st1, st2) <= std::min(en1, en2));
    };

    auto [st, en] = range[0];
    for (auto &[cur_st, cur_en] : range)
    {
        if (intersect(st, en, cur_st, cur_en))
        {
            st = std::min(st, cur_st);
            en = std::max(en, cur_en);
        }
        else
        {
            merged.emplace_back(st, en);
            st = cur_st;
            en = cur_en;
        }
    }

    merged.emplace_back(st, en);

    i64 ans = 0;    
    // print(range)
    // print(merged)

    auto f = [&](int x) -> i64
    {
        return 1LL * x * (x + 1) / 2;
    };

    for (auto &[st, en] : merged)
        ans += f(en - st + 1);

    std::cout << ans << '\n';
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