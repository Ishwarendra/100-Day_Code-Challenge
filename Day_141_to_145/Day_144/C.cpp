#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

void solve()
{
    long long n;
    std::cin >> n;

    long long ans = std::lcm(n - 1, 1) - std::gcd(n - 1, 1);

    if (n == 2)
    {
        std::cout << "0\n";
        return;
    }

    if (n % 2)
    {
        ans = std::max(ans, std::lcm(n / 2, n / 2 + 1) - std::gcd(n / 2, n / 2 + 1));
    }
    else
    {
        ans = std::max(ans, std::lcm(n / 2 - 1, n / 2 + 1) - std::gcd(n / 2, n / 2 + 1));
        long long to = 0;
        if ((n / 2) & 1)
            to = std::lcm(n / 2 - 2, n / 2 + 2) - std::gcd(n / 2 - 2, n / 2 + 2);
        else
            to = std::lcm(n / 2 - 1, n / 2 + 1) - std::gcd(n / 2 - 1, n / 2 + 1);

        ans = std::max(ans, to);
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