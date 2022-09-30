#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::string s;
    std::cin >> n >> s;

    std::vector<int> a(n), can_be(n);
    i64 sum = 0;

    for (int i = 0; i < n; ++i)  
    {
        if (s[i] == 'L')
            a[i] = i;
        else
            a[i] = n - i - 1;

        sum += a[i];  
        can_be[i] = std::max(i, n - i - 1) - a[i];
    }

    std::sort(std::rbegin(can_be), std::rend(can_be));
    
    for (int i = 0; i < n; i++)
    {
        sum += can_be[i];
        std::cout << sum << " \n"[i == n - 1];
    }
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