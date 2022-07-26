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
    
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> a(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i].first;
        a[i].second = i;
    }

    std::sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i)
        std::cout << a[a[i].second].first << " ";
    
    return 0;
}