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
    std::string s, t;
    std::cin >> n >> s >> t;

    auto f = [&](std::string &a)
    {
        std::vector<int> x;
        for (int i = 0; i < n - 1; i++)
            if (a[i] != a[i + 1])
                x.emplace_back(i);

        return x;
    };

    auto a = f(s);
    auto b = f(t);

    print(a, b)

    if (s[0] != t[0] or s.back() != t.back() or std::size(a) != std::size(b))
        std::cout << "-1\n";
    else
    {
        i64
         ans = 0;
        for (int i = 0; i < std::size(a); i++)
            ans += abs(a[i] - b[i]);

        std::cout << ans << '\n';
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