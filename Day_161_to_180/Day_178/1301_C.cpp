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

    i64 c_cnt = (n - m) % (m + 1);
    i64 f_cnt = (m + 1) - c_cnt;

    std::function<i64(int, int)> C = [&](int n, int r) -> i64
    {
        if (r > n)
            return 0LL;
        if (r == 0)
            return 1LL;

        return 1LL * n * C(n - 1, r - 1) / r;
    };

    i64 zeroes = (n - m) / (m + 1);
    print(zeroes, f_cnt, c_cnt)

    i64 ans = C(n, 2) - f_cnt * C(zeroes, 2) - c_cnt * C(zeroes + 1, 2);
    ans += m;

    std::cout << std::max(0LL, ans) << "\n";
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