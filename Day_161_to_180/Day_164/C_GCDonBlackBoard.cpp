#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

template<typename T, class F = std::function<T(const T&, const T&)>>
struct SegmentTree
{
    const int n;
    T null_val;
    std::vector<T> tree;
    F f;

    SegmentTree(const std::vector<T> &in, T null_val, const F& f) 
        : n(std::size(in)), tree(2 * n, null_val), f(f), null_val(null_val)
    {
        for (int i = 0; i < n; ++i)
            tree[i + n] = in[i];

        for (int i = n - 1; i >= 0; i--)
        {
            tree[i] = f(tree[i << 1], tree[i << 1 | 1]);
        }
    }
    void add(int id, T x)
    {
        T val = x - get(id, id);
        update(id, val);
    }
    void update(int id, T val)
    {
        for (tree[id += n] = val; id > 1; id >>= 1)
            tree[id >> 1] = f(tree[id], tree[id ^ 1]);
    }
    T get(int l, int r) 
    {
        r++;
        T res = null_val;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1)
                res = f(res, tree[l++]);
            if (r & 1)
                res = f(res, tree[--r]);
        }

        return res;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    
    SegmentTree<int> st(a, 0, [&](int x, int y)
    {
        return std::gcd(x, y);
    });

    int ans = std::max(st.get(1, n - 1), st.get(0, n - 2));
    for (int i = 1; i < n - 1; ++i)
    {
        int cur = std::gcd(st.get(0, i - 1), st.get(i + 1, n - 1));
        ans = std::max(ans, cur);
    }

    std::cout << ans << "\n";

    return 0;
}