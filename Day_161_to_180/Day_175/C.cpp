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
    int n, c, q;
    std::cin >> n >> c >> q;

    std::string s;
    std::cin >> s;

    std::vector<std::tuple<i64, i64, i64>> range(c);
    i64 prev = n;

    int pos = 0;
    for (auto &[l, r, len] : range)
    {
        std::cin >> l >> r;
        l--, r--;
        len = r - l + 1 + prev;
        prev = len;
    }

    while (q--)
    {
        i64 k;
        std::cin >> k;

        std::function<i64(i64, int)> inv = [&](i64 x, int id)
        {
            if (x < n or id == -1)
                return x;

            auto [l, r, len] = range[id];

            if (len - (r - l + 1) <= x and x <= len - 1)
                return inv(x - (len - 1 - r), id);

            return inv(x, id - 1);
        };

        i64 id = inv(k - 1, c - 1);
        assert(id < n);
        std::cout << s[id] << "\n";
    }
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