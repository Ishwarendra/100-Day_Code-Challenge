#include <bits/stdc++.h>


#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

template <typename T>
struct Fenwick
{
    const int n;
    std::vector<T> a;

    Fenwick(int n) : n(n), a(n) {}
    Fenwick(const std::vector<T> &inp) : Fenwick((int) inp.size())
    {
        for (int i = 0; i < n; i++)
            add(i, inp[i]);
    }
    void add(int x, T v)
    {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }
    T sum(int x)
    {
        T ans = 0;
        x++;
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
    T rangeSum(int l, int r)
    {
        if (l - 1 < 0)
            return sum(r);

        return sum(r) - sum(l - 1);
    }
};

void solve()
{
    int n, m, q;
    std::cin >> n >> m >> q;

    std::vector<std::string> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    std::vector<int> grid(n * m);
    for (int j = 0; j < m; ++j)
    {
        for (int i = 0; i < n; ++i)
            grid[j * n + i] = a[i][j] == '*';
    }

    Fenwick<int> ft(grid);
    int sz = n * m;

    while (q--)
    {
        int x, y;
        std::cin >> x >> y;
        --x, --y;


        if (grid[y * n + x])
            ft.add(y * n + x, -1);
        else
            ft.add(y * n + x, 1);
        grid[y * n + x] ^= 1;

        int stars = ft.rangeSum(0, sz - 1);
        int dots = stars - ft.rangeSum(0, stars - 1);
        print(stars, dots)
        std::cout << dots << "\n";
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;

    while (t--)
        solve();

    return 0;
}