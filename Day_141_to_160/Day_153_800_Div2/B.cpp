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
    
    int n, k;
    std::cin >> n >> k;

    std::vector<int> h(n);
    for (int i = 0; i < n; ++i)
        std::cin >> h[i];

    int cnt = 0;
    for (int i = 0; i < n; ++i)
        cnt += h[i] >= k;

    std::cout << cnt << "\n";
    
    return 0;
}