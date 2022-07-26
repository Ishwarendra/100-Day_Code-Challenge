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

    std::vector<i64> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    std::sort(std::begin(a), std::end(a));

    const int LIMIT = 200;
    if (n > LIMIT)
    {
        int pos = n - 1;
        for (int i = 100; i < LIMIT; i++)
            a[i] = a[pos--];

        n = LIMIT;
    }

    std::set<i64> s;
    for (int i = 0; i < n; i++)
        s.emplace(a[i]);

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            for (int k = j + 1; k < n; ++k)
                if (!s.count(a[i] + a[j] + a[k]))
                {
                    std::cout << "NO\n";
                    return;
                }
        }
    }

    std::cout << "YES\n";
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