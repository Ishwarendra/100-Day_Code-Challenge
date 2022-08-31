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
    int n, s;
    std::cin >> n >> s;

    std::vector<i64> a(n);
    for (int i = 0; i < n; ++i)  
        std::cin >> a[i];

    auto pref = a;
    for (int i = 1; i < n; ++i)
        pref[i] += pref[i - 1];

    int ans = std::upper_bound(std::begin(pref), std::end(pref), s) - std::begin(pref);
    int miss = 0;

    for (int i = 0; i < n; i++)
    {
        if (i - 1 >= 0 and pref[i - 1] > s)
            break;

        s += a[i];

        int cur_ans = std::upper_bound(std::begin(pref), std::end(pref), s) - std::begin(pref) - 1;
        
        if (ans < cur_ans)
        {
            ans = cur_ans;
            miss = i + 1;
        }

        s -= a[i];
    }

    std::cout << miss << "\n";
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