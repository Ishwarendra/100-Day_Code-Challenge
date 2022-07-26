#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    if (n == 1)
    {
        std::cout << "1\n";
        return;
    }   

    std::vector<int> p(n);
    p[0] = n;

    for (int i = 1; i < n; i++)
        p[i] = i;

    for (int i : p)
        std::cout << i << " ";
    std::cout << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}