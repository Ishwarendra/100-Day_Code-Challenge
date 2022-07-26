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
    i64 k;
    std::cin >> k;

    i64 left = 1, right = 1e5;
    int row = 0;

    while (left <= right)  
    {
        i64 mid = (left + right) >> 1;

        if (mid * mid >= k)
            row = mid, right = mid - 1;
        else
            left = mid + 1;
    }

    auto f = [&](int j, bool col = false) -> i64
    {
        if (col)
            return 1LL * row * row - (row - 1) - (row - j);

        return 1LL * row * row - j + 1;
    };  
    left = 1, right = i64(row);

    while (left <= right)
    {
        i64 mid = (left + right) >> 1;

        if (f(mid) > k)
            left = mid + 1;
        else if (f(mid) < k)
            right = mid - 1;
        else
        {
            std::cout << row << " " << mid << "\n";
            return;
        }
    }

    left = 1, right = i64(row);

    while (left <= right)
    {
        i64 mid = (left + right) >> 1;

        if (f(mid, true) > k)
            right = mid - 1;
        else if (f(mid, true) < k)
            left = mid + 1;
        else
        {
            std::cout << mid << " " << row << "\n";
            return;
        }
    }

    std::cout << "baka\n";
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