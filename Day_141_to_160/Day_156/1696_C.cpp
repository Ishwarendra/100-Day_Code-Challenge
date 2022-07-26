#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    int k;
    std::cin >> k;

    std::vector<int> b(k);
    for (int i = 0; i < k; ++i)
        std::cin >> b[i];

    std::vector<std::pair<int, i64>> f1, f2;

    auto get = [&](std::vector<int> &c, std::vector<std::pair<int, i64>> &f)
    {
        int sz = std::size(c);

        for (int i = 0; i < sz; i++)
        {
            int cnt = 1;
            while (c[i] % m == 0)
                c[i] /= m, cnt *= m;

            if (f.empty())
                f.emplace_back(c[i], cnt);
            else if (f.back().first == c[i])
                f.back().second += cnt;
            else
                f.emplace_back(c[i], cnt);
        }
    };

    get(a, f1), get(b, f2);
    std::cout << (f1 == f2 ? "Yes\n" : "No\n");
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