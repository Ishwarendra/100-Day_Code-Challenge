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
    std::string s, t;
    std::cin >> n >> s >> t;  

    std::vector cnt(26, std::vector<int>(26));
    for (int i = 0; i < n; ++i)
    {
        if (s[i] > t[i])
        {
            std::cout << "-1\n";
            return;
        }
        else if (s[i] < t[i])
            cnt[s[i] - 'a'][t[i] - 'a']++;
    }

    int ans = 0;

    for (int i = 0; i < 26; i++)
    {
        int mn = -1;
        for (int j = i + 1; j < 26; j++)
        {
            if (cnt[i][j] == 0)
                continue;

            if (mn == -1)
            {
                mn = j;
                cnt[i][j] = 0;
                ans++;
                break;
            }
        }

        if (mn != -1)
        {
            for (int j = mn + 1; j < 26; j++)
                cnt[mn][j] += cnt[i][j];
        }
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