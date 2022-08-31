#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    // freopen("buckets.in", "r", stdin);
    // freopen("buckets.out", "w", stdout);

    // constexpr int n = 10;
    int n;
    std::cin >> n;
    std::array<int, 2> lake, barn, rock;

    for (int i = 0; i < n; ++i)
    {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < n; ++j)
        {
            if (s[j] == 'L')
                lake = {i, j};
            else if (s[j] == 'R')
                rock = {i, j};
            else if (s[j] == 'B')
                barn = {i, j};
        }
    }

    auto between = [](int a, int b, int c)
    {
        return std::min(b, c) <= a and a <= std::max(b, c);
    };

    int ans = -1 + std::abs(barn[0] - lake[0]) + std::abs(barn[1] - lake[1]);
    if (lake[0] == rock[0] and rock[0] == barn[0] 
        and between(rock[0], lake[0], barn[0]))
        std::cout << ans + 2 << "\n";
    else if (lake[1] == rock[1] and rock[1] == barn[1]
            and between(rock[1], lake[1], barn[1]))
        std::cout << ans + 2 << "\n";
    else
        std::cout << ans << "\n";

    return 0;
}
