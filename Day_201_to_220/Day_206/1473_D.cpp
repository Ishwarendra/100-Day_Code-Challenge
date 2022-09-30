#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
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

void solve()
{
    int n, m;
    std::string s;
    std::cin >> n >> m >> s;

    std::vector<std::array<int, 3>> a(n + 1);
    std::vector<int> left(n + 1), right(n + 1);

    for (int i = 0; i < n; i++)
    {
        auto [l, r, x] = a[i];
        int to_add = (s[i] == '+' ? 1 : -1);
        x += to_add;
        l += to_add;
        r += to_add;

        a[i + 1] = {l , r, x};
        left[i + 1] = x;
        right[i + 1] = x;
    }

    SparseTable<int> max(right, [&](const int &x, const int &y) { return std::max(x, y); });
    SparseTable<int> min(left, [&](const int &x, const int &y) { return std::min(x, y); });

    while (m--)
    {
        int l, r;
        std::cin >> l >> r;

        int ini_l = min.get(0, l - 1);
        int ini_r = max.get(0, l - 1);

        auto rem = a[r][2] - a[l - 1][2];
        if (r < n)
        {
            int fin_l = min.get(r + 1, n);
            int fin_r = max.get(r + 1, n);

            fin_l -= rem, fin_r -= rem;
            ini_l = std::min(fin_l, ini_l);
            ini_r = std::max(ini_r, fin_r);
        }

        std::cout << ini_r - ini_l + 1 << "\n";
    }
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