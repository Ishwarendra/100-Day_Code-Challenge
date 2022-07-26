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
    i64 n, w;
    std::cin >> n >> w;

    std::vector<std::pair<i64, int>> a;
    for (int i = 0; i < n; ++i)  
    {
        i64 x;
        std::cin >> x;

        if (x > w)
            continue;
        else
            a.emplace_back(x, i);
    }

    n = std::size(a);
    std::sort(std::begin(a), std::end(a));

    std::vector<int> ans;
    i64 sum = 0;

    for (int i = n - 1; i >= 0; --i)
    {
        sum += a[i].first;
        ans.emplace_back(a[i].second + 1);
        if (sum >= (w + 1) / 2 and sum <= w)
        {
            std::sort(std::begin(ans), std::end(ans));

            std::cout << std::size(ans) << "\n";
            for (int ele : ans)
                std::cout << ele << " ";
            std::cout << "\n";
            return;
        }
    }

    std::cout << "-1\n";
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