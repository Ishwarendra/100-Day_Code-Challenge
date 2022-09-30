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

    std::vector a(4, std::vector<std::string>(n));
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < n; ++j)
            std::cin >> a[i][j];
    }

    std::ranges::sort(a);

    auto get = [&](int cur)
    {
        int ans = 0;
        int st = cur;

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < n; ++j)
            {
                for (int k = 0; k < n; ++k)
                {
                    if (a[i][j][k] - '0' != cur)
                        ans++;

                    cur ^= 1;
                }
            }
        }

        return ans;
    };

    int ans = 1e9;
    do
    {
        ans = std::min({ans, get(0), get(1)});

    } while (std::next_permutation(std::begin(a), std::end(a)));

    std::cout << ans;

    return 0;
}