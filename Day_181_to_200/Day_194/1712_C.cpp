#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
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
    std::vector<int> last(n + 1, -1);

    for (int i = 0; i < n; ++i)  
    {
        std::cin >> a[i];
        last[a[i]] = i;
    }

    int ans = 0, st = 0;
    std::vector<int> stop(1);

    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            bool can = true;
            int en = last[a[i]];
            std::set<int> distinct;

            while (can)
            {
                can = false;
                for (int j = en; j >= st; j--)
                {
                    if (last[a[j]] > en)                    
                    {
                        can = true;
                        en = last[a[j]];
                    }
                }

                st = last[a[i]];
            }

            for (int j = en; j >= stop.back(); j--)
            {
                distinct.emplace(a[j]);
                a[j] = 0;
            }

            stop.emplace_back(en + 1);
            distinct.erase(0);
            ans += std::size(distinct);
        }
    }

    std::cout << ans << std::endl;
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