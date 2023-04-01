#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, p, q;
    std::cin >> n >> p >> q;

    std::string s;
    std::cin >> s;

    // q -> up (c -> b -> a)
    // p -> down (a -> b -> c)
    std::vector<int> up(n);
    for (int i = 0; i < n; i++)  
        up[i] = s[i] - 'a';

    int left = 0, right = n - 1;
    int ans = -1;

    std::array<int, 2> g_use{};
    // is it possible to make s[0..mid] = "aaa...a"
    auto good = [&](int mid)
    {
        std::vector u(std::begin(up), std::begin(up) + mid + 1);
        std::sort(std::begin(u), std::end(u));

        std::array<int, 2> use{};
        for (int i = 0; i <= mid; i++)
        {
            if (u[i] == 0)
                continue;

            if (use[0] + u[i] <= q)
                use[0] += u[i];
            else if (use[1] + 26 - u[i] <= p)
                use[1] += 26 - u[i];
            else
                return false;
        }

        g_use = use;
        return true;
    };

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (good(mid))
            ans = mid, left = mid + 1;
        else
            right = mid - 1;
    }

    p -= g_use[1], q -= g_use[0];
    if (ans == n - 1)
        std::cout << std::string(n, 'a') << "\n";
    else
    {
        std::cout << std::string(ans + 1, 'a');

        for (int i = ans + 1; i < n; i++)
        {
            int d = (26 - up[i]) % 26;
            if (p >= d)
                p -= d, s[i] = 'a';
            else
                s[i] -= q, q = 0;

            std::cout << s[i];
        }
        std::cout << "\n";
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