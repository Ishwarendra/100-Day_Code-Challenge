#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

std::vector<std::string> a;
void init()
{
    i64 i = 1;
    int cnt = 0;
    while (cnt++ <= 60)
    {
        a.push_back(std::to_string(i));
        i *= 2;
    }
}   

void solve()
{
    std::string n;
    std::cin >> n;

    auto check = [&](std::string &s, std::string &t)
    {
        int i = 0, j = 0, del = 0;
        while (i < std::size(s) and j < std::size(t))
        {
            if (s[i] == t[j])
                i++, j++;
            else 
                i++, del++;
        }

        int res = (int)std::size(t) - j + del + (int)std::size(s) - i;
        return res;
    };

    int ans = 1e4;
    for (int i = 0; i < std::size(a); i++)
        ans = std::min(ans, check(n, a[i]));

    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    init();

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}