#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);

    std::vector<int> c(3), m(3);
                         
    for (int i = 0; i < 3; ++i)
        std::cin >> c[i] >> m[i];

    for (int j = 0; j < 100; ++j)
    {
        int to_pour = std::min(c[(j + 1) % 3] - m[(j + 1) % 3], m[j % 3]);
        m[(j + 1) % 3] += to_pour;
        m[j % 3] -= to_pour;
    }

    for (int i = 0; i < 3; ++i)
        std::cout << m[i] << "\n";

    return 0;
}