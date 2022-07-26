#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

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

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 x;
    std::cin >> x;

    i64 num = x;

    std::map<i64, i64, std::greater<i64>> pf;
    while (x % 2 == 0)
        pf[2]++, x >>= 1;

    for (i64 i = 3; i * i <= x; i += 2)
    {
        while (x % i == 0)
            pf[i]++, x /= i;
    }

    if (x > 1)
        pf[x]++;

    std::vector<std::pair<i64, i64>> m;
    for (auto [p, f] : pf)
        m.emplace_back(p, f);

    i64 a = 1, a_temp = 1;
    i64 b = num, b_temp = 1;
    int skip = 0;

    std::function<void(int)> f;
    f = [&](int i)
    {
        if (i == std::size(m))
        {
            b_temp = num / a_temp;
            if (std::max(a_temp, b_temp) < std::max(a, b))
            {
                a = a_temp;
                b = b_temp;
            }

            return;
        }

        f(i + 1);

        a_temp *= power(m[i].first, m[i].second);
        f(i + 1);
        a_temp /= power(m[i].first, m[i].second);
    };

    f(0);
    std::cout << a << ' ' << b;

    return 0;
}