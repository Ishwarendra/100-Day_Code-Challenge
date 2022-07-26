#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

void solve()
{
    int l, r;
    std::cin >> l >> r;

    for (int i = l; i < std::min(l + 100, r - 2); i++)
    {
        if ((i ^ (i + 1) ^ (i + 2) ^ (i + 3)) == 0)
        {
            std::cout << i << " " << i + 1 << " " << i + 2 <<  " " << i + 3 << "\n";
            return;
        } 
    }  

    std::cout << "-1\n";
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