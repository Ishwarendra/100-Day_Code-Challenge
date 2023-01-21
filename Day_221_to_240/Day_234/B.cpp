#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<int> odd, even;

    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;

        (x % 2 ? odd : even).emplace_back(x);
    }

    std::sort(std::begin(odd), std::end(odd));
    std::sort(std::begin(even), std::end(even));

    int ans = -1;
    if (std::size(odd) > 1)
    {
        int sz = std::size(odd);
        ans = std::max(odd[sz - 1] + odd[sz - 2], ans);
    }

    if (std::size(even) > 1)
    {
        int sz = std::size(even);
        ans = std::max(ans, even[sz - 1] + even[sz - 2]);
    }

    std::cout << ans;
    
    return 0;
}