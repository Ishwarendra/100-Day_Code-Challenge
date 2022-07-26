#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

void solve()
{
    int x;
    std::cin >> x;

    auto getBit = [&](int x, int pos)
    {
        return (x >> pos) & 1;
    };

    auto setBit = [&](int x, int pos)
    {
        return x | (1 << pos);
    };

    std::vector<int> set, unset;

    for (int i = 0; i < 31; i++)
    {
        if (getBit(x, i))
            set.push_back(i);
        else
            unset.push_back(i);
    }

    int y = 0;
    y = setBit(y, set[0]);

    if (set.size() == 1)
        y = setBit(y, unset[0]);

    std::cout << y << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while(t--)
        solve();
    
    return 0;
}