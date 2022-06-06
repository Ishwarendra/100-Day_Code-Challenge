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

    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);

    int x, y;
    std::cin >> x >> y;

    int factor = 1, d = 0, sign = 1;

    for (int i = x; i != y;)
    {
        while (abs(i - x) != factor)
        {
            if (i == y)
                break;

            i += sign, d++;
        }

        factor *= 2;
        sign *= -1;
    }

    std::cout << d << "\n";
    
    return 0;
}