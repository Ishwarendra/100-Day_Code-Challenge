#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    i64 n;
    std::cin >> n;

    std::vector<i64> a(n);
    std::multiset<i64> m;
    i64 ans = 0;

    int dost = 0;
    int remHalf = n;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
        if (a[i] == -1)
            dost = i;
    }

    for (int i = n - 1; i > dost; i--)
    {
        m.emplace(a[i]);
        int cnt = remHalf / 2 - 1;
        ans += *m.begin();
        m.erase(m.begin());

        while (cnt--)
        {
            i--;
            if (i == dost)
            {
                std::cout << ans << "\n";
                return 0;
            }

            m.emplace(a[i]);
        }

        remHalf /= 2;
    }

    std::cout << ans << "\n";
    
    return 0;
}