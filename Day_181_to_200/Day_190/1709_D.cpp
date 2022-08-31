#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

template <typename T = int, class F = std::function<T(const T&, const T&)>>
class SparseTable
{
public:
    const int n;
    std::vector<std::vector<T>> mat;
    F func;

    SparseTable(const std::vector<T>& a, const F& f) : func(f), n(std::size(a))
    {
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
        assert(0 <= from && from <= to && to <= n - 1);
        int lg = 32 - __builtin_clz(to - from + 1) - 1;
        return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(m);
    for (int i = 0; i < m; ++i)
        std::cin >> a[i];

    SparseTable<int> max(a, [&](const int &x, const int &y) {return std::max(x, y);});

    int q;
    std::cin >> q;

    while (q--)
    {
        int x1, x2, y1, y2, k;
        std::cin >> x1 >> y1 >> x2 >> y2 >> k;

        x1--, y1--;
        x2--, y2--;

        if (y1 > y2)
            std::swap(x1, x2), std::swap(y1, y2);

        if (std::abs(x1 - x2) % k or std::abs(y1 - y2) % k)
            std::cout << "NO\n";
        else
        {
            if (max.get(y1, y2) - 1 < x1)
                std::cout << "YES\n";
            else
            {
                i64 jump = (max.get(y1, y2) - 1 - x1) / k + 1;
                jump *= k;

                if (jump + x1 < n)
                    std::cout << "YES\n";
                else
                    std::cout << "NO\n";
            }
        }
    }

    return 0;
}