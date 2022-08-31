#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

template <typename T = int, class F = std::function<T(const T&, const T&)>>
struct SparseTable
{
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
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)  
        std::cin >> a[i];

    SparseTable<int> max(a, [&](const int &x, const int &y) { return std::max(x, y); });

    for (int i = 1; i < n - 1; i++)
    {
        if (max.get(0, i - 1) > a[i] and a[i] < max.get(i + 1, n - 1))
        {
            std::cout << "NO\n";
            return;
        }
    }

    std::cout << "YES\n";
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