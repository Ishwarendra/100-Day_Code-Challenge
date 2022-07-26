#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(...) 1;
#define print(...) 1;
#endif

constexpr int MOD = 998244353;

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


void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::map<int, int> id, num;
    for (int i = 0; i < n; ++i)
    {
        int x;
        std::cin >> x;

        id[--x] = i;
        num[i] = x;
    }

    std::vector<int> b(k), in_b(n);
    for (int i = 0; i < k; ++i)
    {
        std::cin >> b[i];
        b[i]--;
        in_b[b[i]] = 1;
    }

    Z ans = 1;
    for (int cur : b)
    {
        if (!id.count(cur))
        {
            std::cout << "0\n";
            return;
        }

        int left = 0, right = 0;
        int i = id[cur];
        auto it = num.find(i);

        if (it != num.begin())
        {
            --it;

            if (!in_b[it->second])
            {
                left = 1;
                id.erase(it->second);
                num.erase(it);
            }
        }

        it = num.find(i);
        if (it != num.end() and ++it != num.end())
        {
            if (!in_b[it->second])
                right = 1;

            if (!left and right)
            {
                id.erase(it->second);
                num.erase(it);
            }
        }

        in_b[cur] = 0;
        ans *= (left + right);
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