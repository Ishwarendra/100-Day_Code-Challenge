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

    std::map<int, int> m;

    for (int i = 0; i < n; ++i)  
    {
        int x;
        std::cin >> x;

        m[x]++;
    }

    int st = 0, en = 0, odd = 0;

    for (auto &p : m)
    {
        if (p.second >= 2)
            st++, en++;
        else
        {
            if (st < en)
                st++;
            else
                en++;

            odd++;
        }
    }

    std::cout << odd % 2 + std::min(st, en) << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while(t--)
        solve();
    
    return 0;
}