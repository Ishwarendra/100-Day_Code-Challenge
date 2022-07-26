#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

std::vector<i64> dp;

void solve()
{
    i64 l, r;
    std::cin >> l >> r;

    i64 en = std::upper_bound(std::begin(dp), std::end(dp), r) - std::begin(dp);
    en--;
    i64 st = std::lower_bound(std::begin(dp), std::end(dp), l) - std::begin(dp);
    st--;

    std::cout << std::max(0LL, en - st) << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    // for (int i = 1; i <= 9; i++)
    //     dp.emplace_back(i);

    std::function<void(i64, int, int)> f;
    f = [&](i64 st, int nonZero, int id)
    {
        // Base Case
        if (id == 18)
        {
            dp.emplace_back(st);
            return;
        }    

        if (nonZero == 3)
            f(st * 10, nonZero, id + 1);
        else
        {
            for (int i = 0; i < 10; ++i)
                f(st * 10 + i, nonZero + (i != 0), id + 1);
        }
    };
    
    f(0, 0, 0);
    // for (int i = 1; i <= 9; ++i)
    //     f(i, 1);

    dp.emplace_back(1e18);

    std::sort(std::begin(dp), std::end(dp));
    dp.erase(std::unique(std::begin(dp), std::end(dp)), std::end(dp));
       
    print(dp.back())

    int t;
    std::cin >> t;

    while (t--)
        solve();
    
    return 0;
}