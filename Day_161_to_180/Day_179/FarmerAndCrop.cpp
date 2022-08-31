#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9 + 10;

struct segtree
{
    const int n;
    std::vector<int> tree;

    segtree(int n) : n(n), tree(4 * n, inf) {}

    void update(int i, int x, int p, int ns, int ne)
    {
        if (ns == ne)
            tree[p] = x;
        else
        {
            int nm = (ns + ne) / 2;

            if (i <= nm)
                update(i, x, p * 2 + 1, ns, nm);
            else
                update(i, x, p * 2 + 2, nm + 1, ne);

            tree[p] = std::min(tree[(p << 1) + 1], tree[(p << 1) + 2]);
        }
    } 

    void update(int p, int x)
    {
        update(p, x, 0, 0, n - 1);
    }

    std::pair<int, int> query(int l, int r, int p, int ns, int ne)
    {
        if (ns > r or ne < l)
            return {inf, -1};

        if (ns == ne)
            return {tree[p], ns};

        int nm = (ns + ne) / 2;
        auto [minl, idl] = query(l, r, (p << 1) + 1, ns, nm);
        auto [minr, idr] = query(l, r, (p << 1) + 2, nm + 1, ne);

        if (minl < minr)
            return {minl, idl};
        else
            return {minr, idr};
    }

    auto query(int l, int r)
    {
        return query(l, r, 0, 0, n - 1);
    }
};

int main()
{
    int n;
    std::cin >> n;

    segtree st(n);
    int q;
    std::cin >> q;

    while (q--)
    {
        int t;
        std::cin >> t;

        if (t == 1)
        {
            int i, c;
            std::cin >> i >> c;

            st.update(i, c);
        }
        else
        {
            int l, r, w;
            std::cin >> l >> r >> w;
            r--;

            int count = 0;

            while (true)
            {
                auto [min, min_id] = st.query(l, r);
                if (min > w)
                    break;

                st.update(min_id, inf);
                count++;
            }

            std::cout << count << ",\n";
        }
    }
}

// 7, 2, 0, 2, 9, 1, 4, 6, 3, 2, 5, 3, 1, 2, 0, 3, 0, 1, 0, 3, 0, 0, 2, 0, 0, 19, 0, 0, 1, 1, 0, 2, 0, 2, 1, 1, 0, 0, 0, 0, 0, 3, 0, 0, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 0, 1, 0, 0, 13, 0, 2, 0, 0, 1, 1, 2, 0, 1, 5, 0, 0, 0, 0, 0, 0, 0, 0, 2, 4, 0, 6, 6, 2, 2, 0, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 2, 0, 0, 1