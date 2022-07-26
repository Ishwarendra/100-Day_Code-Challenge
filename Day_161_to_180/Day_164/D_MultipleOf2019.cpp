#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;
constexpr int MOD = 2019;

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
        return power(*this, 1343); // phi(2019) = 1344
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

    std::string s;
    std::cin >> s;

    int n = std::size(s);
    std::vector<Z> a(n);
    a[0] = Z(s[0] - '0');

    for (int i = 1; i < n; i++)
    {
        a[i] = a[i - 1];
        a[i] *= 10;
        a[i] += s[i] - '0';
    }

    auto print_Z = [&]()
    {
        for (int i = 0; i < n; ++i)
            std::cout << a[i] << " \n"[i == n - 1];
    };

    // print_Z();
    for (int i = 0; i < n; i++)
        a[i] /= power(Z(10), i);
    // print_Z();

    std::map<int, int> m;
    m[0]++;
    i64 ans = 0;

    for (int i = 0; i < n; ++i)
    {
        ans += m[a[i].val()];
        m[a[i].val()]++;
    }

    std::cout << ans << "\n";

    return 0;
}