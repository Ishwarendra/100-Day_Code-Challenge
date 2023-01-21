#include "bits/stdc++.h"

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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    int min = *std::min_element(std::begin(a), std::end(a));
    int max = *std::max_element(std::begin(a), std::end(a));

    std::array<int, 2> cnt{};

    for (int i = 0; i < n; i++)
    {
        cnt[0] += a[i] == min;
        cnt[1] += a[i] == max;
    }

    if (min == max)
        std::cout << 1LL * cnt[0] * (cnt[1] - 1) << "\n";
    else
        std::cout << 1LL * cnt[0] * cnt[1] * 2 << "\n";
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