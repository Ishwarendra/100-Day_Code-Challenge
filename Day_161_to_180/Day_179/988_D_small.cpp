#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::map<int, int> m;
    std::vector<int> x(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> x[i];
        m[x[i]] = 1;
    }

    std::vector<int> ans;

    for (auto b : x)
    {
        for (int p = 0; p <= 30; p++)
        {
            std::vector<int> cur(1, b);
            if (m.contains(b - (1 << p)))
                cur.emplace_back(b - (1 << p));
            if (m.contains(b + (1 << p)))
                cur.emplace_back(b + (1 << p));

            if (std::size(cur) > std::size(ans))
                ans = cur;
        }

    }

    std::cout << std::size(ans) << "\n";
    for (int i : ans)
        std::cout << i << ' ';
    
    return 0;
}