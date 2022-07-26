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
    
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);

    int n;
    std::cin >> n;

    std::vector<int> a(n), id(n);

    for (int i = 0; i < n; ++i)    
    {
        std::cin >> a[i];
        a[i]--;
    }

    for (int i = 0; i < n; ++i)
        std::cin >> id[i];
    
    auto inverse = [&]()
    {
        std::vector<int> b(n);

        for (int i = 0; i < n; ++i)
            b[a[i]] = i;

        return b;
    };

    a = inverse();
    std::vector<int> nid = id;

    for (int j = 0; j < 3; ++j)
    {
        for (int i = 0; i < n; ++i)
            nid[a[i]] = id[i];

        std::swap(id, nid);
    }

    for (int i : id)
        std::cout << i << "\n";

    return 0;
}