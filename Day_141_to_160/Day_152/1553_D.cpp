#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

void solve()
{
    std::string s, t;
    std::cin >> s >> t;

    int n = s.size(), m = t.size();

    int j = m - 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == t[j])
        {
            j--;
            continue;
        }

        i--;
    }

    std::cout << (j < 0 ? "YES\n" : "NO\n");
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