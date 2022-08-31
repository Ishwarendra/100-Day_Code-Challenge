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

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)  
        std::cin >> a[i];

    auto find = [&](int x)
    {
        for (int i = 0; i < n; i++) 
            if (a[i] == x)
                return i;

        return -1;
    };

    int st = 0;

    for (int i = 0; i < n and st < n; i++)
    {
        int min = std::min_element(std::begin(a) + st, std::end(a)) - std::begin(a);
        std::rotate(std::begin(a) + st, std::begin(a) + min, std::begin(a) + min + 1);
        st = std::max(min, st + 1);
    }

    for (int i = 0; i < n; ++i)
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