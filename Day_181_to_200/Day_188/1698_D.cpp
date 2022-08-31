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
    int n;
    std::cin >> n;

    auto query = [&](int l, int r)
    {
        std::cout << "? " << l + 1 << " " << r + 1 << std::endl;
        int cnt = 0;

        for (int i = 0; i < r - l + 1; i++)
        {
            int x;
            std::cin >> x;

            cnt += l + 1 <= x and x <= r + 1;
        }

        return cnt % 2;
    };  

    int left = 0, right = n - 1;
    int ans = 0;

    while (left <= right)
    {
        int mid = (left + right) >> 1;

        auto good = query(left, mid);
        if (good)
            right = mid - 1, ans = mid;
        else
            left = mid + 1;
    }

    std::cout << "! " << ans + 1 << std::endl; 
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