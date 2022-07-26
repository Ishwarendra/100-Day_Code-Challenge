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
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    std::sort(a.begin(), a.end());

    auto good = [&](i64 mid, std::vector<int> &b, int add)
    {
        i64 ones = (mid + 1) / 2 - add; // floor wen we add 1 to back
        i64 twos = mid / 2;

        i64 op1 = 0, op2 = 0;
        int can_reduce = 0;

        for (int i = 0; i < n; i++)
        {
            i64 diff = b[n - 1] - b[i];

            op2 += diff / 2;
            op1 += diff % 2;
        }

        if (op2 > twos)
        {
            op1 += 2LL * (op2 - twos);
            op2 = twos;
        }

        return op1 <= ones and op2 <= twos;
    };

    std::vector<int> b;
    auto get = [&](int add)
    {
        b = a;
        b.back() += add;

        i64 left = 0, right = 1e18;
        i64 ans = 0;

        while (left <= right)
        {
            i64 mid = (left + right) / 2LL;
            if (good(mid, b, add))
                ans = mid, right = mid - 1;
            else
                left = mid + 1;
        }
        return ans;
    };

    i64 ans = std::min({get(0), get(1)});
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