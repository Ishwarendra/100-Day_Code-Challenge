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
    
    std::freopen("herding.in", "r", stdin);
    std::freopen("herding.out", "w", stdout);

    int a, b, c;
    std::cin >> a >> b >> c;

    int min = std::min(b - a, c - b);
    int max = std::max(b - a, c - b);

    if (max == 1)
        std::cout << "0\n0";
    else if (max == 2)
        std::cout << "1\n1";
    else
        std::cout << (min == 2 ? 1 : 2) << "\n" << max - 1;


    return 0;
}
