#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        m[x]++;
    }

    std::vector<int> a;
    for (auto [num, f] : m)
        a.emplace_back(f);
    
    std::sort(std::begin(a), std::end(a));
    i64 ans = 0;
    print(a)
    for (int i = 0; i < std::size(a); ++i)
    {
        for (int j = 1; j <= a[i]; j++)         
        {
            auto it = std::begin(a) + i;
            i64 cur = 0;
            // j, 2j, 4j
            for (int k = 1; k <= a.back(); k *= 2)
            {
                auto temp = std::lower_bound(it, std::end(a), j * k);
                // print(i, j, j * k, temp == std::end(a))
                if (temp == std::end(a))
                    break;

                cur += j * k;
                it = ++temp;
            }
            // print(i, j, cur)
            ans = std::max(ans, cur);
        }
    }

    std::cout << ans;

    return 0;
}