#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::map<int, int, std::greater<int>> m;
    for (int i = 0; i < n; i++)  
    {
        int x;
        std::cin >> x;

        m[x]++;
    }

    int cnt = 0;
    for (auto &[num, f] : m)
    {
        if (num % 2)
            continue;

        if (num % 2 == 0)
            m[num]--, m[num / 2]++, cnt++;
    }

    std::cout << cnt << "\n";
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