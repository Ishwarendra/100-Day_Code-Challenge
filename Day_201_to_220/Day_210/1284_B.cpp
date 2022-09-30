#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;
constexpr int N = 1e6 + 10;

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

    std::vector<std::vector<int>> a(n);
    std::vector<int> has(n);

    i64 ans = 0;

    for (int i = 0; i < n; i++)   
    {
        int len;
        std::cin >> len;

        a[i].resize(len);
        for (int j = 0; j < len; ++j)
        {
            std::cin >> a[i][j];
            a[i][j] += 3;
        }

        int min = inf;
        for (auto ele : a[i])
        {
            if (ele > min)
                has[i] = 1;

            min = std::min(min, ele);
        }

        if (!has[i])
            ans += std::size(std::set(std::begin(a[i]), std::end(a[i]))) > 1;

        std::sort(std::begin(a[i]), std::end(a[i]));
    }

    ans += std::accumulate(std::begin(has), std::end(has), 0);
    Fenwick<int> ft(N);

    for (int i = 0; i < n; ++i)
    {
        if (has[i])
        {
            ans += i;
            ft.add(0, 1);
        }
        else
        {
            ans += ft.rangeSum(0, a[i].back() - 1);
            ft.add(a[i].front(), 1);
        }
    }

    std::fill(std::begin(ft.a), std::end(ft.a), 0);

    for (int i = 0; i < n; i++)
    {

        if (has[i])
        {
            ans += i;
            ft.add(N - 1, 1);
        }
        else
        {
            ans += ft.rangeSum(a[i].front() + 1, N - 1);
            ft.add(a[i].back(), 1);
        }
    }

    std::cout << ans;
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