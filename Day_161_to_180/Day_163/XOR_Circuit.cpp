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

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> adj[n];
    for (int i = 0; i < n - 2; ++i)
    {
        int u, v;
        std::cin >> u >> v;

        adj[--u].push_back(--v);
        adj[v].push_back(u);
    }

    std::vector<std::vector<Z>> dp(n, std::vector<Z>(4));
    std::vector<std::vector<int>> vis(n, std::vector<int>(4));

    std::function<Z(int, int, int)> dfs;
    dfs = [&](int u, int p, int x)
    {   
        if (u == n - 1)
            return Z(x == 0);

        if (vis[u][x])
            return dp[u][x];

        vis[u][x] = 1;
        bool leaf = true;
        for (int i = 0; i < 4; ++i)
        {
            Z val = 1;
            for (int v : adj[u])
            {
                if (v == p)
                    continue;

                leaf = false;
                val *= dfs(v, u, i);
            }

            dp[u][x] += val;
        }

        if (leaf)
            dp[u][x] -= 3;

        return dp[u][x];
    }; 

    std::cout << 4 * dfs(0, -1, 0) << "\n"; 
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