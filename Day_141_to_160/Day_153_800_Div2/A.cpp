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
    
    std::cout << std::fixed;
    std::cout << std::setprecision(8); 

    int n;
    std::cin >> n;

    std::cout << ((n + 1) / 2 ) / (1.0L * n) << "\n";
    
    return 0;
}