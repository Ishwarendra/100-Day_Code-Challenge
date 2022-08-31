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

    std::vector<std::array<int, 2>> ans;
    int c = (n + 1) / 2;
    for (int i = c + 1; i < n; i++)  
        ans.emplace_back(i, i + 1);

    ans.emplace_back(n, c);

    for (int i = 3; i <= c; i++)
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