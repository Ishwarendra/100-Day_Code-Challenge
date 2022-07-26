#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

void solve()
{
    int n;
    std::cin >> n;

    auto query = [&](int l, int r) -> std::vector<int>
    {
        std::cout << "? " << l + 1 << " " << r + 1 << std::endl;
        std::vector<int> a(r - l + 1);
        for (int i = 0; i < r - l + 1; ++i)
        {
            std::cin >> a[i];
            a[i]--;
            
            if (a[i] == -2)
                return {-1};
        }

        return a;
    };

    auto good = [&](std::vector<int> &a, int l, int r)
    {
        int cnt = 0;
        for (int i = 0; i < std::size(a); ++i)
            cnt += a[i] >= l and a[i] <= r;

        print(a, l, r, cnt)
        return cnt % 2;
    };

    int left = 0, right = n - 1, ans = -1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        std::vector<int> a = query(0, mid);

        if (a[0] == -1)
        {
            std::cout << "baka\n";
            return;
        }

        if (good(a, 0, mid)) // if odd then unchanged ele somewhere in this range
            right = mid - 1, ans = mid;
        else // check other half
            left = mid + 1;
    }
    
    std::cout << "! " << ans + 1 << "\n";
}

int main()
{
    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}