#include <bits/stdc++.h>

#define LOCAL

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> p(n), s(n);

    for (int i = 0; i < n; ++i)  
        std::cin >> p[i];

    for (int i = 0; i < n; ++i)
        std::cin >> s[i];

    

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