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
    
    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);

    int c, n;
    std::cin >> c >> n;

    std::multiset<int> chicken;
    std::vector<std::pair<int, int>> cows(n);

    for (int i = 0; i < c; ++i)
    {
        int x;
        std::cin >> x;

        chicken.emplace(x);
    }

    for (int i = 0; i < n; ++i)
        std::cin >> cows[i].first >> cows[i].second;

    std::sort(std::begin(cows), std::end(cows), 
        [&](const std::pair<int, int> &a, const std::pair<int, int> &b)
        {
            return a.second < b.second;
        });

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        auto it = chicken.lower_bound(cows[i].first);
        if (it == chicken.end() or (*it) > cows[i].second)
            continue;
        
        ans++;
        chicken.erase(it);
    }

    std::cout << ans;
    
    return 0;
}
