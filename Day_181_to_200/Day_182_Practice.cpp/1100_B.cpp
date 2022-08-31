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
    
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> pos(n);
    auto ans = std::string(m, '0');

    for (int i = 0; i < m; i++)
    {   
        int x;
        std::cin >> x;

        pos[x - 1].emplace_back(i);
    }

    for (int i = 0; i < n; ++i)
        std::reverse(std::begin(pos[i]), std::end(pos[i]));

    while (true)
    {
        int max = -1;
        bool no = false;

        for (auto &p : pos)
        {
            if (p.empty())
                no = true;
        }

        if (no)
            break;

        for (auto &p : pos)
        {
            max = std::max(max, p.back());
            p.pop_back();
        }

        ans[max] = '1';
    }

    std::cout << ans;
    
    return 0;
}