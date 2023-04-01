#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::freopen("tracing.in", "r", stdin);
    std::freopen("tracing.out", "w", stdout);

    int n, t;
    std::string s;
    std::cin >> n >> t >> s;

    std::vector a(t, std::array<int, 3>());
    for (auto &[time, u, v] : a)
    {
        std::cin >> time >> u >> v;
        u--, v--;
    }

    std::sort(std::begin(a), std::end(a));
    auto possible = [&](int src, int k)
    {
        std::string t(n, '0');  
        std::vector<int> count(n);
        t[src] = '1';

        for (auto &[time, u, v] : a)
        {
            bool should = t[v] == '1';
            if (t[u] == '1' and count[u] < k)
                t[v] = '1', count[u]++;
            if (should and t[v] == '1' and count[v] < k)
                t[u] = '1', count[v]++;
        }
        
        return t == s;
    };

    constexpr int limit = 250;
    int cnt = 0;
    int max = -1, min = limit;


    for (int cow = 0; cow < n; cow++)
    {
        int can = 0;
        for (int k = 0; k <= limit; k++)
        {
            if (possible(cow, k))
            {
                max = std::max(max, k);
                min = std::min(min, k);
                can = 1;
            }
        }

        cnt += can;
    }

    std::cout << cnt << " " << min << " ";
    if (max == limit)
        std::cout << "Infinity";
    else
        std::cout << max;
    
    return 0;
}
