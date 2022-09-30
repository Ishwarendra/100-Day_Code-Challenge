#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    if (std::size(std::set(std::begin(a), std::end(a))) > k)
    {
        std::cout << "-1\n";
        return;
    }

    std::set<int> b(std::begin(a), std::end(a));
    while (std::size(b) != k)
    {
        for (int j = 1; j <= n; j++)
        {
            if (!b.count(j))
            {
                b.emplace(j);
                break;
            }
        }
    }

    std::vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        for (int ele : b)
            ans.push_back(ele);
    }

    std::cout << std::size(ans) << "\n";
    for (int i = 0; i < std::size(ans); ++i)
        std::cout << ans[i] << " ";
    std::cout << "\n";
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