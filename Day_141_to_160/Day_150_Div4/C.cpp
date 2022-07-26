#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a;
    std::map<int, int> m;
    for (int i = 0; i < n; ++i)
    {
        int x;
        std::cin >> x;

        m[x % 10]++;
    }

    for (auto &p : m)
    {
        if (p.second >= 1)
            a.push_back(p.first);

        if (p.second >= 2)
            a.push_back(p.first);

        if (p.second >= 3)
            a.push_back(p.first);
    }
    print(a)
    for (int i = 0; i < a.size(); ++i)
    {
        for (int j = i + 1; j < a.size(); ++j)
        {
            for (int k = j + 1; k < a.size(); ++k)
            {
                if ((a[i] + a[j] + a[k]) % 10 == 3)
                {
                    print(a[i], a[j], a[k])
                    std::cout << "YES\n";
                    return;
                }
            }
        }
    }

    std::cout << "NO\n";
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