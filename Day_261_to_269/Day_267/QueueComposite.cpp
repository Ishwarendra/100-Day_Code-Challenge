#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int MOD = 998244353;

int power(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b % 2)
            res = (1LL * res * a) % MOD;
        a = (1LL * a * a) % MOD;
        b /= 2;
    }
    return res;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int q;
    std::cin >> q;

    std::queue<std::pair<int, int>> queue;
    int coeff = 1, constant = 0;

    while (q--)
    {
        int t;
        std::cin >> t;

        if (t == 0)
        {
            int a, b;
            std::cin >> a >> b;

            queue.emplace(a, b);
            coeff = (1LL * coeff * a) % MOD;
            constant = (1LL * constant * a) % MOD;
            constant = (constant + b) % MOD;
        }
        else if (t == 1)
        {
            auto [a, b] = queue.front();
            queue.pop();

            coeff = (1LL * coeff * power(a, MOD - 2)) % MOD;
            constant -= (1LL * b * coeff) % MOD;
            if (constant < 0)
                constant += MOD;
        }
        else
        {
            int x;
            std::cin >> x;

            int ans = (1LL * coeff * x) % MOD;
            std::cout << (ans + constant) % MOD << "\n";
        }
    }

    return 0;
}