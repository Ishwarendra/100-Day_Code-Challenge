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

    i64 sum = 0;
    for (int i = 0; i < n; i++)  
    {
        int x;
        std::cin >> x;
        sum += x;
    }

    std::vector<int> b(n);
    for (int i = 0; i < n; i++)
        std::cin >> b[i];

    sum += std::accumulate(std::begin(b), std::end(b), 0LL);
    sum -= *std::max_element(std::begin(b), std::end(b));

    std::cout << sum << "\n";
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