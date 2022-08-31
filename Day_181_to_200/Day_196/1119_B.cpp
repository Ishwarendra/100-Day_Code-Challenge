#include <bits/stdc++.h>

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
    
    int n, h;
    std::cin >> n >> h;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    int left = 1, right = n;
    int ans = 1;

    auto good = [&h](int mid, std::vector<int> b)
    {
        std::sort(std::begin(b), std::begin(b) + mid);
        int rem = h;
        int count = 0;
        for (int i = mid - 1; i > 0; i -= 2)
        {
            if (b[i] <= rem)
            {
                count += 2;
                rem -= b[i];
            }
            else
                break;
        }

        if (mid % 2 and rem >= b[0])
            count++;

        return count == mid;
    };

    while (left <= right)
    {
        int mid = (left + right) >> 1;

        if (good(mid, a))
            ans = mid, left = mid + 1;
        else
            right = mid - 1;
    }

    std::cout << ans << "\n";
    
    return 0;
}