#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

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
    to = std::min(to, n - 1);
    assert(0 <= from && from <= to && to <= n - 1);
    int lg = 32 - __builtin_clz(to - from + 1) - 1;
    return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
  }
}; 

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> monster(n);
    for (int i = 0; i < n; ++i)
        std::cin >> monster[i];

    int m;
    std::cin >> m;

    int max_endu = 0;
    std::vector<std::pair<int, int>> hero(m); // power, endurance
    for (int i = 0; i < m; ++i)
    {
        std::cin >> hero[i].first >> hero[i].second;
        max_endu = std::max(max_endu, hero[i].second);
    }

    std::sort(std::begin(hero), std::end(hero), [](auto a, auto b)
        {
            if (a.second == b.second)
                return a.first > b.first;

            return a.second > b.second;
        }); 

    std::vector<std::pair<int, int>> a;
    for (int i = 0; i < m; ++i) 
    {
        if (a.empty())
            a.emplace_back(hero[i]);
        else if (a.back().second != hero[i].second)
            a.emplace_back(hero[i]);
    }

    std::vector<int> endurance(max_endu + 1, -1);
    for (auto [p, e] : a)
        endurance[e] = p;

    for (int i = max_endu - 1; i >= 0; i--)
        endurance[i] = std::max(endurance[i], endurance[i + 1]);
    print(endurance)
    SparseTable<int> max(monster, [&](int x, int y) { return std::max(x, y); });
    int ans = 0;
    for (int i = 0; i < n;)
    {
        for (int j = 1; j <= max_endu; j++)
        {
            // print(endurance[j], monster[i], max.get(i, i + j))
            if (j == 1 and endurance[j] < max.get(i, i + j - 1))
            {
                std::cout << "-1\n";
                return;
            }

            if (endurance[j] >= max.get(i, i + j - 1) and j != max_endu)
                continue;
            else if (j == max_endu and endurance[j] >= max.get(i, i + j - 1))
                ans++, i += j;
            else
            {
                ans++, i += j - 1;
                break;
            }
        }
    }

    std::cout << ans << "\n";
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