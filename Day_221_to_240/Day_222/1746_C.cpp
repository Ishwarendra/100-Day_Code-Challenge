#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n + 1);
    for (int i = 0; i < n; i++)  
    {
        int x;
        std::cin >> x;
        a[x] = i + 1;
    }

    std::reverse(std::begin(a), std::end(a));
    for (int i = 0; i < n; i++)
        std::cout << a[i] << " \n"[i == n - 1]; 
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