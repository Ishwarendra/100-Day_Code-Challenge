#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::multiset<int> s;
    for (int i = 0; i < n; i++)  
    {
        int x;
        std::cin >> x;
        s.emplace(x);
    }

    std::vector<int> b(m, 0);
    for (int i = 0; i < m; i++)
        std::cin >> b[i];

    for (int i = 0; i < m; i++)
    {
        s.erase(std::begin(s));
        s.emplace(b[i]);
    }

    std::cout << std::accumulate(std::begin(s), std::end(s), 0LL) << "\n";
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