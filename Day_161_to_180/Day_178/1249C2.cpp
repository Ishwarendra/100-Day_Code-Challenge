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

void solve()
{
    i64 n;
    std::cin >> n;

    std::vector<int> base3;
    auto good = [&](i64 n)
    {
        bool ans = true;

        while (n)
        {
            base3.emplace_back(n % 3);
            if (n % 3 == 2)
                ans = false;

            n /= 3;
        }

        return ans;
    };

    if (good(n))
        std::cout << n << "\n";
    else
    {
        i64 nex = 0;
        i64 sz = std::size(base3);
        bool can = true;
        
        int st = 0;

        for (int i = sz - 1; i >= 0; i--)
        {
            if (base3[i] == 2)
            {
                while (i < sz and base3[i] != 0)
                    i++;
                if (i == sz)
                    can = false;
                else
                    st = i;

                break;
            }
        }

        if (can)
        {
            base3[st] = 1;

            for (int i = st; i < sz; ++i)
                nex += power(3LL, i) * base3[i];
        }
        else
            nex = power(3LL, sz);

        assert(nex >= n);
        std::cout << nex << "\n";
    }
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