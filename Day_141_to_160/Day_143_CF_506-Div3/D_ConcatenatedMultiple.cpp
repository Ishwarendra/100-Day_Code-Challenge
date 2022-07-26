#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

using i64 = long long;

template<class T>
T power(T a, T b, T mod) {
    T res = 1;
    for (; b; b /= 2, a = (a * a) % mod) {
        if (b % 2) {
            res = (res % mod) * (a % mod) % mod;
        }
    }
    return (res % mod);
} 

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);

    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    auto size = [&](i64 x)
    {
        int len = 0;

        while (x)
            x /= 10, len++;

        return len;
    };

    std::vector<i64> p10(1, 1LL);
    for (int i = 1; i <= 11; i++)
        p10.push_back(p10.back() * 10LL % k);

    std::map<int, std::map<int, int>> g;

    for (int i = 0; i < n; ++i)
        g[size(a[i])][a[i] % k]++;

    i64 ans = 0;

    for (int i = 0; i < n; i++)
    {
        int my_sz = size(a[i]);
        int my_rem = a[i] % k;

        for (int j = 1; j <= 10; ++j)
        {
            int need = k - (a[i] * p10[j]) % k;

            if (need == k)
                need = 0;

            ans += g[j][need];

            if (j == my_sz)
                ans -= (my_rem == need);
        }
    }

    std::cout << ans << "\n";
    
    return 0;
}