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

    std::vector<int> phi;
    for (int i = 1; i < n; i++)
    {
        if (std::gcd(i, n) == 1)
            phi.emplace_back(i);
    }

    const int mod = n;
    int product = 1;
    for (int i = 0; i < std::size(phi); i++)
        product = (1LL * product * phi[i]) % mod;

    if (product != 1)
    {
        int p = 1;
        std::cout << std::size(phi) - 1 << "\n";
        for (int i = 0; i < std::size(phi) - 1; i++)
        {
            p = (1LL * p * phi[i]) % mod;
            std::cout << phi[i] << " ";
        }

        std::cout << "\n"; 
        assert(p == 1);
    }
    else
    {
        std::cout << std::size(phi) << "\n";
        for (int i : phi)
            std::cout << i << " ";

        std::cout << "\n";
    }

    return 0;
}