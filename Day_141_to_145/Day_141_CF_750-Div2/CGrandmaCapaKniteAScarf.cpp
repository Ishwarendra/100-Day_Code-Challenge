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
    std::string s;

    std::cin >> n >> s;  

    std::vector<int> cnt(26);

    for (int i = 0; i < n; ++i)
        cnt[s[i] - 'a']++;

    auto f = [&](char ch) -> int
    {
        int i = 0, j = n - 1, ans = 0;
        while (i < j)
        {
            if (s[i] == s[j])
                i++, j--;
            else 
            {
                if (s[i] == ch)
                    i++, ans++;
                else if (s[j] == ch)
                    j--, ans++;
                else
                    return 1e9;
            }
        }

        return ans;
    };

    int ans = 1e9;

    for (char ch = 'a'; ch <= 'z'; ch++)
        ans = std::min(ans, f(ch));

    std::cout << (ans == 1e9 ? -1 : ans) << "\n";
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