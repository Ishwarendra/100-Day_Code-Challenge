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
    
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)    
        std::cin >> a[i];

    std::vector<int> b = a;
    std:sort(std::begin(b), std::end(b));

    int cnt = 0;
    for (int i = 0; i < n; i++)
        cnt += a[i] != b[i];

    std::cout << cnt - 1 << "\n";

    return 0;
}
