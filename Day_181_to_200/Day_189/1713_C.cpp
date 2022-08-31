#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

std::set<int> squares;

void solve()
{
    int n;
    std::cin >> n; 

    std::vector<int> a(n);
    for (int i = n - 1; i >= 0; i--)
    {
        auto it = squares.lower_bound(i);
        int to_put = (*it) - i;

        if (to_put > n - 1)
        {
            std::cout << "-1\n";
            return;
        }

        int end = to_put;

        while (i > end)
        {
            a[i] = to_put;
            i--, to_put++;
        }

        a[i] = to_put;
    }

    for (int i = 0; i < n; i++)
    {
        assert(squares.count(a[i] + i));
        std::cout << a[i] << " \n"[i == n - 1];
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    squares.emplace(0);
    int i = 1;
    while (i * i <= 1e6)
    {
        squares.emplace(i * i);
        i++;
    }

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}