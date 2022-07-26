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
    std::vector<int> a(11);
    std::map<int, int> m;
    for (int i = 0; i < 11; ++i)  
    {
        std::cin >> a[i];
        m[a[i]]++;
    }

    int k;
    std::cin >> k;
    
    std::sort(std::rbegin(a), std::rend(a));

    int min = a[k - 1];
    int have = m[min];
    int need = 0;

    for (int i = 0; i < k; i++)   
    {
        if (a[i] == min)
            need++;
    }

    print(min, need, a)

    std::function<i64(int, int)> C = [&](int n, int r) -> i64
    {
        if (r == 0)
            return 1LL;

        return 1LL * n * C(n - 1, r - 1) / r;
    };

    std::cout << C(have, need) << "\n";
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