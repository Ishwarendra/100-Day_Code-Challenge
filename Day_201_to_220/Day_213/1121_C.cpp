#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;

    std::queue<std::pair<int, int>> q;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        a[i] = x;
        q.emplace(x, i);
    }

    int m = 0;
    auto tested = [&]() { return (100 * m + n / 2) / n; };
    
    std::vector<int> rem(n, inf), interesting(n);
    int cnt = 0;

    while (true)
    {
        while (!q.empty() and cnt < k)
        {
            auto [val, id] = q.front();
            rem[id] = val;
            q.pop();
            cnt++;
        }   

        int min = *std::min_element(std::begin(rem), std::end(rem));
        for (int i = 0; i < n; ++i)
        {
            int from = a[i] - rem[i] + 1;

            if (rem[i] == inf or tested() - from >= min)
                continue;

            if (from <= tested() and tested() <= a[i])
            {
                if (!interesting[i])
                    interesting[i] = 1;
            }
        }

        for (int i = 0; i < n; ++i)
        {
            if (rem[i] == inf)
                continue;

            if (rem[i] == min)
                rem[i] = inf, cnt--, m++;
            else
                rem[i] -= min;
        }

        if (min == inf)
            break;
    }   

    std::cout << std::accumulate(std::begin(interesting), std::end(interesting), 0);
    return 0;
}