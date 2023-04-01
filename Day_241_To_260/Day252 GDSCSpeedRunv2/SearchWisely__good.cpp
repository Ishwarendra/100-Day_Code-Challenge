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

    int left = -1, right = -1;
    for (int i = 0, j = n - 1; i < n and j >= 0; i++, j--)
    {
        if (a[i] == k)
            right = i;
        if (a[j] == k)
            left = j;
    }

    std::cout << left << ' ' << right;
    
    return 0;
}