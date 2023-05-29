#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

template<class T>
T power(T a, i64 b) 
{
    T res = 1;
    for (; b; b /= 2, a *= a) 
    {
        if (b % 2) 
            res *= a;
    }
    return res;
}

template <typename T>
T inverse(T a, T m) 
{
    T u = 0, v = 1;
    while (a != 0) 
    {
        T t = m / a;
        m -= t * a; 
        u -= t * v; 
        std::swap(a, m);
        std::swap(u, v);
    }
    assert(m == 1);
    return u;
}

template<int P>
struct MInt 
{
    int x;
    constexpr MInt() : x{} {}
    constexpr MInt(i64 x) : x{norm(x % getMod())} {}
    
    static int Mod;
    constexpr static int getMod() 
    {
        if (P > 0) 
            return P;
        else 
            return Mod;
    }
    constexpr static void setMod(int Mod_) { Mod = Mod_; }
    constexpr int norm(int x) const 
    {
        if (x < 0) 
            x += getMod();
        
        if (x >= getMod()) 
            x -= getMod();
        
        return x;
    }
    constexpr int val() const { return x; }
    explicit constexpr operator int() const { return x; }
    constexpr MInt operator-() const 
    {
        MInt res;
        res.x = norm(getMod() - x);
        return res;
    }
    constexpr MInt inv() const 
    {
        assert(x != 0);
        return MInt(inverse(x, P));
    }
    constexpr MInt &operator*=(MInt rhs) & 
    {
        x = 1LL * x * rhs.x % getMod();
        return *this;
    }
    constexpr MInt &operator+=(MInt rhs) & 
    {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MInt &operator-=(MInt rhs) & 
    {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MInt &operator/=(MInt rhs) & 
    {
        return *this *= rhs.inv();
    }
    friend constexpr MInt operator*(MInt lhs, MInt rhs) 
    {
        MInt res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MInt operator+(MInt lhs, MInt rhs) 
    {
        MInt res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MInt operator-(MInt lhs, MInt rhs) 
    {
        MInt res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MInt operator/(MInt lhs, MInt rhs) 
    {
        MInt res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr std::istream &operator>>(std::istream &is, MInt &a) 
    {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const MInt &a) { return os << a.val(); }
    friend constexpr bool operator==(MInt lhs, MInt rhs) { return lhs.val() == rhs.val(); }
    friend constexpr bool operator!=(MInt lhs, MInt rhs) { return lhs.val() != rhs.val(); }
};
 
template<>
int MInt<0>::Mod = 1;
 
template<int V, int P>
constexpr MInt<P> CInv = MInt<P>(V).inv();

constexpr int P = 998244353;
using Z = MInt<P>;

class Solution 
{
    const int M = 2 * 5 * 11 * 13 * 23 + 1;
    void makePrefix(std::vector<Z> &a, bool rev)
    {
        int n = std::size(a);
        if (rev)
        {
            for (int i = n - 2; i >= 0; i--)
                a[i] += a[i + 1];
        }
        else
        {
            for (int i = 1; i < n; i++)
                a[i] += a[i - 1];
        }
    }
public:
    std::string shortestPalindrome(std::string s) 
    {
        int n = std::size(s);
        std::vector<Z> hash(n), rhash(n);
        Z prod = 1;
        for (int i = 0; i < n; i++) 
            hash[i] = s[i] * prod, prod *= M;

        prod = 1;
        for (int i = n - 1; i >= 0; i--)
            rhash[i] = s[i] * prod, prod *= M;

        makePrefix(hash, false);
        makePrefix(rhash, true);

        std::string ans;
        for (int i = n - 1; i >= 0; i--)
        {
            Z rev = rhash[0];
            if (i + 1 < n)
                rev -= rhash[i + 1];

            if (rev == hash[i] * power<Z>(M, n - i - 1))
            {
                if (i == n - 1)
                    ans = s;
                else
                {
                    std::string extra = s.substr(i + 1);
                    std::reverse(std::begin(extra), std::end(extra));
                    ans = extra + s.substr(0, i + 1);
                    std::reverse(std::begin(extra), std::end(extra));
                    ans += extra;
                }

                break;
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    std::string s;
    std::cin >> s;

    std::cout << sol.shortestPalindrome(s);
    return 0; 
}    