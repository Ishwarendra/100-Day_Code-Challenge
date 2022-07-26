#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

std::vector<int> f;

void init()
{
    int i = 0;
    while (std::size(f) <= 1000)
    {
        i++;
        if (i % 3 == 0 or i % 10 == 3)
            continue;

        f.push_back(i);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    init();

    int t = 1;
    std::cin >> t;
    
    while (t--)
    {
        int k;
        std::cin >> k;

        std::cout << f[k - 1] << "\n";
    }
    
    return 0;
}