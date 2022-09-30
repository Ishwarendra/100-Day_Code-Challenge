#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e8;

template <typename T = int, class F = std::function<T(const T&, const T&)>>
class SparseTable
{
public:
    const int n;
    std::vector<std::vector<T>> mat;
    F func;
    T null;

    SparseTable(const std::vector<T>& a, const F& f) : func(f), n(std::size(a))
    {
        null = {-inf, -inf};
        int max_log = 32 - __builtin_clz(n);
        mat.resize(max_log);
        mat[0] = a;
        for (int j = 1; j < max_log; j++)
        {
            mat[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); i++)
                mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);

        }
    }

    T get(int from, int to) const
    {
        if (0 <= from && from <= to && to <= n - 1)
        {
            int lg = 32 - __builtin_clz(to - from + 1) - 1;
            return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
        }
        return null;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, totc, totd;
    std::cin >> n >> totc >> totd;

    auto max = [&](auto & a, auto & b)
    {
        return std::max(a, b);
    };

    constexpr int N = 1e5 + 1;

    std::vector<std::array<int, 2>> diamond(N, { -inf, -inf}), coin(N, { -inf, -inf});

    for (int i = 0; i < n; ++i)
    {
        int b, c;
        char ch;
        std::cin >> b >> c >> ch;

        if (ch == 'C')
        {
            if (coin[c][0] <= b)
                coin[c][1] = coin[c][0], coin[c][0] = b;
            else if (coin[c][1] <= b)
                coin[c][1] = b;
        }
        else
        {
            if (diamond[c][0] <= b)
                diamond[c][1] = diamond[c][0], diamond[c][0] = b;
            else if (diamond[c][1] <= b)
                diamond[c][1] = b;
        }
    }

    SparseTable<std::array<int, 2>> maxc(coin, max);
    SparseTable<std::array<int, 2>> maxd(diamond, max);

    int ans = 0;
    for (int c1 = 0; c1 <= totc; ++c1)
    {
        int b = coin[c1][0];
        if (b == -inf)
            continue;

        // 1. coin + coin = c1: 0 to totc - c1 and c1 + 1 to totc;
        int other_one = -inf;
        if (totc - c1 < c1)
            other_one = maxc.get(0, totc - c1)[0];
        else
            other_one = std::max({maxc.get(0, c1 - 1)[0], maxc.get(c1, c1)[1], maxc.get(c1 + 1, totc - c1)[0]});

        ans = std::max(ans, b + other_one);

        // 2. coin + diamond = c1 and totd
        ans = std::max(ans, b + maxd.get(0, totd)[0]);
    }

    for (int d1 = 0; d1 <= totd; d1++)
    {
        // 3. diamond + diamond
        int b = diamond[d1][0];
        if (b == -inf)
            continue;

        int other_one = -inf;
        if (totd - d1 >= d1)
            other_one = std::max({maxd.get(0, d1 - 1)[0], maxd.get(d1, d1)[1], maxd.get(d1 + 1, totd - d1)[0]});
        else
            other_one = maxd.get(0, totd - d1)[0];

        ans = std::max(ans, b + other_one);
    }

    std::cout << ans;

    return 0;
}