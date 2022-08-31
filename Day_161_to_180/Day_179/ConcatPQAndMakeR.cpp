#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

constexpr int MOD = 1e9 + 7;

// assume -MOD <= x < 2*MOD
int norm(int x) {
    if (x < 0) {
        x += MOD;
    }
    if (x >= MOD) {
        x -= MOD;
    }
    return x;
}
template<class T>
T power(T a, int b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
struct Z {
    int x;
    Z(int x = 0) : x(norm(x)) {}
    int val() const {
        return x;
    }
    Z operator-() const {
        return Z(norm(MOD - x));
    }
    Z inv() const {
        assert(x != 0);
        return power(*this, MOD - 2);
    }
    Z &operator*=(const Z &rhs) {
        x = (long long)(x) * rhs.x % MOD;
        return *this;
    }
    Z &operator+=(const Z &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs) {
        return *this *= rhs.inv();
    }
    friend Z operator*(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, Z &a) {
        int v;
        is >> v;
        a = Z(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Z &a) {
        return os << a.val();
    }
}; 


int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string p, q, r;
    std::cin >> p >> q >> r;

    int a = std::size(p), b = std::size(q), c = std::size(r);
    std::vector dp(c + 1, std::vector<std::vector<Z>>(a + 1, std::vector<Z>(b + 1)));

    dp[0][0][0] = 1;
    Z ans = 0;

    for (int i = 0; i <= c; i++)
    {
        for (int j = 0; j <= a; j++)
        {
            for (int k = 0; k <= b; k++)
            {
                Z val = 0;

                if (i > 0 and j > 0 and r[i - 1] == p[j - 1])
                    val += dp[i - 1][j - 1][k] - (k == 0 ? 0 : dp[i - 1][j - 1][k - 1]);
                if (i > 0 and k > 0 and r[i - 1] == q[k - 1])
                    val += dp[i - 1][j][k - 1] - (j == 0 ? 0 : dp[i - 1][j - 1][k - 1]);

                if (i == c and j > 0 and k > 0) 
                    ans += val;

                dp[i][j][k] += val;
                if (j > 0)
                    dp[i][j][k] += dp[i][j - 1][k];
                if (k > 0)
                    dp[i][j][k] += dp[i][j][k - 1];
                if (j > 0 and k > 0)
                    dp[i][j][k] -= dp[i][j - 1][k - 1];
            }
        }
    }

    std::cout << ans << "\n";
    
    return 0;
}