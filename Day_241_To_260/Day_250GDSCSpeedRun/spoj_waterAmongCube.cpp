#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

// std::vector<int> greaterHeightTower(std::vector<int> &a)
// {
//     int n = a.size();
//     std::vector<int> ans(n);

//     int leftMax = 0, rightMax = 0;
//     int i = 0, j = n - 1;

//     while (i <= j)
//     {
//         if (a[i] < a[j])
//         {
//             leftMax = std::max(leftMax, a[i]);
//             ans[i++] = std::min(leftMax, rightMax);
//         }
//         else
//         {
//             rightMax = std::max(rightMax, a[j]);
//             ans[j--] = std::min(leftMax, rightMax);
//         }
//     }

//     return ans;
// }


template<typename T, class F = std::function<T(const T&, const T&)>>
struct SegmentTree
{
    const int n;
    const T null_val;
    std::vector<T> tree;
    F f;

    template <typename G>
    SegmentTree(const std::vector<G> in, const T null_val, const F& f) 
        : n(int(in.size())), tree(2 * n, null_val), f(f), null_val(null_val)
    {
        for (int i = 0; i < n; ++i)
            tree[i + n] = in[i];

        for (int i = n - 1; i >= 0; i--)
            tree[i] = f(tree[i << 1], tree[i << 1 | 1]);
    }
    void add(int id, T x)
    {
        T val = x - get(id, id);
        update(id, val);
    }
    void update(int id, T val)
    {
        for (tree[id += n] = val; id >>= 1; )
            tree[id] = f(tree[id << 1], tree[(id << 1) | 1]);
    }
    T get(int l, int r) 
    {
        T resL = null_val, resR = null_val;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                resL = f(resL, tree[l++]);
            if (r & 1)
                resR = f(tree[--r], resR);
        }

        return f(resL, resR);
    }
};
void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            std::cin >> a[i][j];
    }

    std::vector<SegmentTree<int>> horizontal, vertical;
    for (int i = 0; i < n; i++)
    {
        horizontal.emplace_back(SegmentTree<int>(a[i], 0, 
            [&](int x, int y){ return std::max(x, y); }));
    }

    for (int j = 0; j < m; j++)
    {
        std::vector<int> x_;
        for (int i = 0; i < n; i++)
            x_.emplace_back(a[i][j]);

        vertical.emplace_back(SegmentTree<int>(x_, 0, 
            [&](int x, int y){ return std::max(x, y); }));
    }

    long long ans = 0;
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < m - 1; j++)
        {
            int left = horizontal[i].get(0, j - 1);
            int right = horizontal[i].get(j + 1, m - 1);
            int up = vertical[j].get(0, i - 1);
            int down = vertical[j].get(i + 1, n - 1);

            int min = std::min({up, down, left, right});
            // std::array _ {up, down, left, right};
            // print(i, j, min, _)
            ans += std::max(0, min - a[i][j]);
        }
    }

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