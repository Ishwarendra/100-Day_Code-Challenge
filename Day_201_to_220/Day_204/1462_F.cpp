#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
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

    std::vector<std::pair<int, int>> a(n);
    for (auto &[l, r] : a)
        std::cin >> l >> r;

    std::vector<int> distinct;
    for (auto &[l, r] : a)
    {
        distinct.push_back(l); 
        distinct.push_back(r);
    }

    std::sort(std::begin(a), std::end(a));

    std::sort(std::begin(distinct), std::end(distinct));
    int sz = std::unique(std::begin(distinct), std::end(distinct)) - std::begin(distinct);
    distinct.resize(sz);

    for (auto &[l, r] : a)
    {
        l = std::lower_bound(std::begin(distinct), std::end(distinct), l) - std::begin(distinct) + 1;
        r = std::lower_bound(std::begin(distinct), std::end(distinct), r) - std::begin(distinct) + 1;
    }

    Fenwick<int> ft(2 * n + 2);

    std::vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        ans[i] += ft.rangeSum(0, a[i].first - 1);
        ft.add(a[i].second, 1);
    }

    std::fill(std::begin(ft.a), std::end(ft.a), 0);
    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] += ft.rangeSum(a[i].second + 1, 2 * n + 1);
        ft.add(a[i].first, 1);
    }
    
    std::cout << *std::min_element(std::begin(ans), std::end(ans)) << "\n";
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