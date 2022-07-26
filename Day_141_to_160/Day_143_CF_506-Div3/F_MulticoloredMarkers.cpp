#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

using i64 = long long; 

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    i64 a, b;
    std::cin >> a >> b;
    
    i64 x = a + b;
    i64 ans = 2 * (1 + a + b);

    std::set<std::pair<long long, long long>> div, diva, divb;

    for (int i = 1; 1LL * i * i <= x; i++)
    {
        if (x % i == 0)
            div.emplace(std::min(i * 1LL, x / i), std::max(i * 1LL, x / i));

        if (a % i == 0)
            diva.emplace(std::min(i * 1LL, a / i), std::max(i * 1LL, a / i));

        if (b % i == 0)
            divb.emplace(std::min(i * 1LL, b / i), std::max(i * 1LL, b / i));    
    }

    while (!div.empty())
    {
        auto cur = div.begin();
        i64 tr_x = cur->first, tr_y = cur->second;

        div.erase(cur);

        auto it_a = diva.upper_bound({tr_x, i64(1e14)});
        auto it_b = divb.upper_bound({tr_x, i64(1e14)});
        bool ok_a = false, ok_b = false;

        if (it_a != diva.begin())
        {
            it_a--;
            print(it_a->first, it_a->second)
            if (it_a->first <= tr_x and it_a->second <= tr_y)
                ok_a = true;
        }

        if (it_b != divb.begin())
        {
            it_b--;
            print(it_b->first, it_b->second)
            if (it_b->first <= tr_x and it_b->second <= tr_y)
                ok_b = true;
        }

        if (ok_a or ok_b)
            ans = std::min(ans, 2LL * (tr_x + tr_y));
    }

    std::cout << ans << "\n";

    return 0;
}