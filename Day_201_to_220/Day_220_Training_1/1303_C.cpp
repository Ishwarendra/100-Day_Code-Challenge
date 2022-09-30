#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

void solve()
{
    std::string s;
    std::cin >> s;

    int n = std::size(s);

    std::vector<int> pos(26, -inf);
    pos[s[0] - 'a'] = 0;
    for (int i = 1; i < n; ++i)  
    {
        if (pos[s[i] - 'a'] == -inf)
        {
            if (!std::count(std::begin(pos), std::end(pos), pos[s[i - 1] - 'a'] + 1))
                pos[s[i] - 'a'] = pos[s[i - 1] - 'a'] + 1;
            else if (!std::count(std::begin(pos), std::end(pos), pos[s[i - 1] - 'a'] - 1))
                pos[s[i] - 'a'] = pos[s[i - 1] - 'a'] - 1;
            else
            {
                std::cout << "NO\n";
                return;
            }
        }
        else if (std::abs(pos[s[i] - 'a'] - pos[s[i - 1] - 'a']) != 1)
        {
            std::cout << "NO\n";
            return;
        }
    }

    std::string ans;
    std::vector<std::pair<int, int>> b(26); 
    for (int i = 0; i < 26; i++)
        b[i] = {pos[i], i};
    
    std::sort(std::begin(b), std::end(b), std::greater());
    
    std::cout << "YES\n";
    for (int i = 0; i < 26; ++i)
        ans += char('a' + b[i].second);

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