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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    int k;
    std::cin >> k;

    auto left = std::lower_bound(std::begin(a), std::end(a), k);
    auto right = std::upper_bound(std::begin(a), std::end(a), k) - 1;

    if (left == std::end(a) or *left != k)
        std::cout << "-1 -1";
    else
        std::cout << (left - std::begin(a)) << " " << (right - std::begin(a)); 
    
    return 0;
}