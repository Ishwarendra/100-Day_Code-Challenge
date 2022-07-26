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
    
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);

    int n;
    std::cin >> n;

    std::vector<int> a(1001);

    for (int i = 0; i < n; ++i)    
    {
        int s, e, b;
        std::cin >> s >> e >> b;

        a[s] += b, a[e + 1] -= b;
    }

    for (int i = 1; i <= 1000; i++)
        a[i] += a[i - 1];

    std::cout << *std::max_element(a.begin(), a.end());
    
    return 0;
}