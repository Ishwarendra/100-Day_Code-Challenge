#include<bits/stdc++.h>

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
    
    int a, b, c;
    std::cin >> a >> b >> c;

    int m;
    std::cin >> m;

    std::vector<std::vector<int>> options(2);

    for (int i = 0; i < m; ++i)
    {
        int cost;
        std::string port;

        std::cin >> cost >> port;
        options[port[0] == 'P'].push_back(cost);
    }   

    for (int i = 0; i < 2; ++i)
        std::sort(std::begin(options[i]), std::end(options[i]), std::greater());

    i64 cost = 0;
    int count = 0;

    while (a--)
    {
        if (!options[0].empty())
        {
            count++;
            cost += options[0].back();
            options[0].pop_back();
        }   
        else
            break;         
    }

    while (b--)
    {
        if (!options[1].empty())
        {
            count++;
            cost += options[1].back();
            options[1].pop_back();
        }
        else
            break;
    }

    std::vector<int> rem(std::size(options[0]) + std::size(options[1]));
    std::merge(std::begin(options[0]), std::end(options[0]), 
               std::begin(options[1]), std::end(options[1]), 
               std::begin(rem), std::greater<int>());
    
    print(rem)
    while (c-- and !rem.empty())
    {
        count++;
        cost += rem.back();
        rem.pop_back();
    }

    std::cout << count << " " << cost << "\n";

    return 0;
}