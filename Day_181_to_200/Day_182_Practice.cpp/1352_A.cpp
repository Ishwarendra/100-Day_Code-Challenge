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
    std::string s;
    std::cin >> s;

    std::vector<std::string> a;
    int n = std::size(s);

    for (int i = 0; i < n; ++i)  
    {
        if (s[i] == '0')
            continue;

        auto cur = std::string(n - i - 1, '0');
        cur = s[i] + cur;
        a.push_back(cur);
    }

    std::cout << std::size(a) << "\n";
    for (int i = 0; i < std::size(a); ++i)
        std::cout << a[i] << " ";
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