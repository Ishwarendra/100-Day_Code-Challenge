#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)  
        std::cin >> a[i];
    std::reverse(a.begin(), a.end());
    
    auto count = [&](int x = 1e6)
    {
        int cnt = 0;
        for (int i = 0; i < std::min(n, x); i++)
        {
            if (a[i] == a[0])
                cnt++;
            else
                break;
        }

        return cnt;
    };

    int ans = 0, cnt = 1;
    while (true)
    {
        cnt = count();
        if (cnt == n)
        {
            std::cout << ans << "\n";
            return;
        }

        ans++;
        cnt *= 2;

        for (int i = 0; i < std::min(cnt, n); i++)
            a[i] = a[0];
    }
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