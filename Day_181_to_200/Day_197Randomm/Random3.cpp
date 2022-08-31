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

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> div(21);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i % j == 0 or j % i == 0)
                div[i].emplace_back(j);
        }

        std::sort(div[i].begin(), div[i].end());
    }
    
    int ans = 0;
    std::vector<int> a(n + 1);
    i64 cnt = 0;
    std::function<void(int)> f = [&](int id)
    {
        cnt++;
        if (id == n + 1)
        {
            ans++;
            return;
        }

        for (int i : div[id])
        {
            if (!a[i])
            {
                a[i] = 1;
                f(id + 1);
                a[i] = 0;
            }
        }
    };

    f(1);
    std::cout << ans;
    assert(cnt <= int(1e9)); // :greentick:

    return 0;
}