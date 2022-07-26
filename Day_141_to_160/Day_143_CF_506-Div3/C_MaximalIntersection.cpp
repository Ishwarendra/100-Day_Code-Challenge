#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

const int inf = 1e9 + 8;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> a(n);
    for (int i = 0; i < n; ++i)
    {
        int l, r;
        std::cin >> l >> r;

        a[i] = {l, r};
    }

    std::sort(a.begin(), a.end());
    int ans = 0;

    std::vector<int> pref_min(n), suff_min(n);
    pref_min[0] = a[0].second;
    suff_min.back() = a.back().second;

    for (int i = 1; i < n; ++i)
        pref_min[i] = std::min(pref_min[i - 1], a[i].second);

    for (int i = n - 2; i >= 0; --i)
        suff_min[i] = std::min(suff_min[i + 1], a[i].second);

    print(a)

    for (int i = 0; i < n; ++i)
    {
        if (i == 0)
            ans = std::max(ans, -a[n - 1].first + suff_min[i + 1]);
        else if (i == n - 1)
            ans = std::max(ans, -a[n - 2].first + pref_min[i - 1]);
        else
        {
            int r = std::min(pref_min[i - 1], suff_min[i + 1]);
            print(i, r, pref_min[i - 1], suff_min[i + 1]);
            ans = std::max(ans, -a[n - 1].first + r);
        }
    }

    std::cout << ans << '\n';

    return 0;
}