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

    i64 tot = std::accumulate(std::begin(a), std::end(a), 0LL);

    auto possible = [&](i64 sum, int len)
    {
        int cnt = 0;
        i64 cur_sum = 0;
        for (int i = 0; i < n; i++)
        {
            cur_sum += a[i];
            if (cur_sum == sum)
                cnt++, cur_sum = 0;
            else if (cur_sum > sum)
                return false;
        }

        return cnt == len;
    };

    for (int len = n; len >= 1; len--)
    {
        // find a subset with sum = tot / len
        i64 to_get = tot / len;
        if (tot % len == 0 and possible(to_get, len))
        {
            std::cout << n - len << "\n";
            return;
        }
    }

    std::cout << "baka\n";
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