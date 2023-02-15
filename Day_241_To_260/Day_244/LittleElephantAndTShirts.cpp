#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

template<class T>
T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

template<int P>
struct MInt {
    int x;
    MInt() : x{} {}
    MInt(i64 x) : x{norm(x % P)} {}

    int norm(int x)
    {
        if (x < 0)
            x += P;
        if (x >= P)
            x -= P;
        return x;
    }
    int val() const { return x; }
    MInt operator-() const
    {
        MInt res;
        res.x = norm(P - x);
        return res;
    }
    MInt inv() const
    {
        assert(x != 0);
        return power(*this, P - 2);
    }
    MInt &operator*=(const MInt &rhs)
    {
        x = 1LL * x * rhs.x % P;
        return *this;
    }
    MInt &operator+=(const MInt &rhs)
    {
        x = norm(x + rhs.x);
        return *this;
    }
    MInt &operator-=(const MInt &rhs)
    {
        x = norm(x - rhs.x);
        return *this;
    }
    MInt &operator/=(const MInt &rhs) { return *this *= rhs.inv(); }
    friend MInt operator*(const MInt &lhs, const MInt &rhs)
    {
        MInt res = lhs;
        res *= rhs;
        return res;
    }
    friend MInt operator+(const MInt &lhs, const MInt &rhs)
    {
        MInt res = lhs;
        res += rhs;
        return res;
    }
    friend MInt operator-(const MInt &lhs, const MInt &rhs)
    {
        MInt res = lhs;
        res -= rhs;
        return res;
    }
    friend MInt operator/(const MInt &lhs, const MInt &rhs)
    {
        MInt res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, MInt &a)
    {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const MInt &a) { return os << a.val(); }
};

constexpr int P = 1e9 + 7;
using Z = MInt<P>;

void solve()
{
    int n;
    std::cin >> n;

    constexpr int N = 100;
    std::vector shirt(n, std::vector<int>(N));

    auto input = [&](int p)
    {
        std::string s;
        std::getline(std::cin, s);

        std::stringstream is(s);
        int x;
        while (is >> x)
            shirt[p][--x] = 1;
    };

    std::cin.ignore();
    for (int i = 0; i < n; i++)
        input(i);

    std::vector<Z> dp(1 << n, 0);
    dp[0] = 1;
    auto getBit = [&](auto x, auto pos) { return (x >> pos) & 1; };

    for (int j = 0; j < N; j++)
    {
        for (int mask = (1 << n) - 1; mask >= 0; mask--)
        {
            auto x = dp[mask];

            for (int i = 0; i < n; i++)
            {
                if (!shirt[i][j] or getBit(mask, i))
                    continue;

                dp[mask | (1 << i)] += x;
            }
        }   
    }

    std::cout << dp[~-(1 << n)] << "\n";
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