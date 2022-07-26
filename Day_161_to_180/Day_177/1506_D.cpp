#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::map<int, int> freq;
    for (int i = 0; i < n; ++i)  
    {
        int x;
        std::cin >> x;

        freq[x]++;
    }

    std::multiset<int, std::greater<int>> m;
    for (auto [_, f] : freq)
        m.emplace(f);

    print(m)
    while (m.size() > 1)
    {
        int max = *std::begin(m);
        m.erase(std::begin(m));
        int sMax = *std::begin(m);
        m.erase(std::begin(m));

        max--, sMax--;
        if (max)
            m.emplace(max);
        if (sMax)
            m.emplace(sMax);
        print(m)
    }
    int rem = (m.empty() ? 0 : *std::begin(m));
    std::cout << rem << "\n"; 
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