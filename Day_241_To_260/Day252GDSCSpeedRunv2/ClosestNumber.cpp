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

    std::sort(std::begin(a), std::end(a));
    int min = 1e9;

    for (int i = 0; i < n - 1; i++)
        min = std::min(min, a[i + 1] - a[i]);

    std::vector<int> res;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i + 1] - a[i] == min)
            res.emplace_back(a[i]), res.emplace_back(a[i + 1]);
    }

    for (auto x : res)
        std::cout << x << " ";
    
    return 0;
}