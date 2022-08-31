#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)  
        std::cin >> a[i];

    int min = inf;
    std::array<int, 2> swap;
    std::sort(std::begin(a), std::end(a));

    for (int i = 1; i < n; i++)
    {
        if (min > std::abs(a[i] - a[i - 1]))
        {
            min = std::abs(a[i] - a[i - 1]);
            swap = {i - 1, i};
        }
    }

    std::swap(a[0], a[swap[0]]);
    std::swap(a[n - 1], a[swap[1]]);

    std::multiset<int> m(std::begin(a) + 1, std::end(a) - 1);

    int pos = 1;
    while (!m.empty())
    {
        auto it = m.lower_bound(a[0]);
        if (it != std::end(m))
        {
            a[pos++] = *it;
            m.erase(it);
        }
        else
        {
            a[pos++] = *std::begin(m);
            m.erase(std::begin(m));
        }
    }

    for (int i = 0; i < n; ++i)
        std::cout << a[i] << " \n"[i == n - 1];
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