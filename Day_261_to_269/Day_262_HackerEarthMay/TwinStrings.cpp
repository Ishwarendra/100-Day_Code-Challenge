#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::string s;
    std::cin >> n >> s;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        int mask = (i == 0 ? 0 : a[i - 1]);
        int ch = s[i] - 'a';
        a[i] = mask ^ (1 << ch);
    }

    std::map<int, int> m;
    i64 ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
            ans++;
        int ch = s[i] - 'a';
        ans += m[a[i]];
        m[a[i]]++;
    }

    std::cout << ans << "\n";
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