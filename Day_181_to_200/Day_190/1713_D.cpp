#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    auto query = [&](int a, int b, int c, int d)
    {
        std::cout << "? " << a << " " << c << std::endl;
        int x;
        std::cin >> x;

        if (x == 1)
        {
            std::cout << "? " << a << " " << d << std::endl;
            std::cin >> x;

            return (x == 1 ? a : d);
        }
        else if (x == 2)
        {
            std::cout << "? " << b << " " << c << std::endl;
            std::cin >> x;

            return (x == 1 ? b : c);
        }
        else
        {
            std::cout << "? " << b << " " << d << std::endl;
            std::cin >> x;

            return (x == 1 ? b : d);
        }
    };

    std::set<int> s;
    for (int i = 1; i <= (1 << n); i++)
        s.emplace(i);

    while (std::size(s) >= 4)
    {
        int sz = std::size(s);
        std::vector<int> winners;

        for (int i = 0; i < sz / 4; i++)
        {
            int a = *std::begin(s);
            int b = *(++std::begin(s));
            s.erase(std::begin(s)), s.erase(std::begin(s));

            int c = *std::begin(s);
            int d = *(++std::begin(s));
            s.erase(std::begin(s)), s.erase(std::begin(s));

            auto winner = query(a, b, c, d);
            winners.emplace_back(winner);
        }

        for (auto winner : winners)
            s.emplace(winner);

        if (std::size(s) == 1)
        {
            std::cout << "! " << winners[0] << std::endl;
            return;
        }
    }

    std::cout << "? " << *(std::begin(s)) << " " << *(++std::begin(s)) << std::endl;
    int x;
    std::cin >> x;

    std::cout << "! " << (x == 1 ? *std::begin(s) : *(++std::begin(s))) << std::endl; 
}

int main()
{
    int t = 1;
    std::cin >> t;

    while (t--)
        solve();

    return 0;
}