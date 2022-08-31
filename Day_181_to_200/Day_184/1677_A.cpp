#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

template <typename T>
struct Fenwick
{
    const int n;
    std::vector<T> a;

    Fenwick(int n) : n(n), a(n) {}
    template<typename G>
    Fenwick(const std::vector<G> in) : Fenwick((int)std::size(in))
    {
        for (int i = 1; i <= n; i++)
        {
            a[i - 1] += in[i - 1];
            if (i + (i & -i) <= n)
                a[i - 1 + (i & -i)] += a[i - 1];
        }
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
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    Fenwick<int> st(n + 1);
    i64 ans = 0;

    st.add(a[0], 1);
    for (int b = 1; b < n - 2; b++)
    {
        Fenwick<int> en(n + 1);
        en.add(a[n - 1], 1);
        for (int c = n - 2; c > b; c--)
        {
            int prefix = st.rangeSum(0, a[c] - 1);
            int suffix = en.rangeSum(0, a[b] - 1);

            if (prefix and suffix)
                ans += 1LL * prefix * suffix;

            en.add(a[c], 1);
        }

        st.add(a[b], 1);
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