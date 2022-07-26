#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> a(n);

    for (int i = 0; i < n; ++i)
    {
        int k;
        std::cin >> k;

        a[i].resize(k);
        for (int j = 0; j < k; ++j)
            std::cin >> a[i][j];
    }

    std::vector<int> b(n);

    for (int i = 0; i < n; i++)
    {
        int pos = 0;
        for (int p : a[i])
            b[i] = std::max(b[i], p - (pos++));
    }

    std::map<std::vector<int>, int> cmp;
    for (int i = 0; i < n; ++i)
        cmp[a[i]] = b[i];

    std::sort(a.begin(), a.end(), 
        [&cmp](std::vector<int> &a, std::vector<int> &b)
        {
            return cmp[a] < cmp[b];
        });

    auto good = [&](i64 x)
    {
        for (auto cave : a)
        {
            for (auto monster : cave)
            {
                if (monster >= x)
                    return false;

                x++;
            }
        }

        return true;
    };

    i64 left = 0, right = 7e18, ans = 0;

    while (left <= right)
    {
        i64 mid = (left + right) / 2;

        if (good(mid))
            ans = mid, right = mid - 1;
        else
            left = mid + 1;
    }

    std::cout << ans << "\n";
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