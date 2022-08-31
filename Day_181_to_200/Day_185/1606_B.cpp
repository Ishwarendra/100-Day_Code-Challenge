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
    i64 n, k;
    std::cin >> n >> k;

    i64 cnt = 0;
    i64 cur = 1;

    while (cur < k)
        cur *= 2, cnt++;

    cnt += (n - cur + k - 1) / k;

    std::cout << cnt << "\n";
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