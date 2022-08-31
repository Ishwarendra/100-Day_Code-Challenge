#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

std::set<char> vowel {'A', 'E', 'I', 'O', 'U'};

void solve()
{
    std::string s;
    std::cin >> s;

    int n = std::size(s);

    auto isVowel = [&](char ch)
    {
        return vowel.count(ch);
    };

    auto f = [&](char ch)  
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ch)
                continue;
            else if (isVowel(ch) == isVowel(s[i]))
                ans += 2;
            else
                ans++;
        }

        return ans;
    };

    int ans = 1e9;
    for (char ch = 'A'; ch <= 'Z'; ch++)
        ans = std::min(ans, f(ch));

    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::freopen("consistency_chapter_1_input.txt", "r", stdin);
    std::freopen("consistency_chapter_1_output.txt", "w", stdout);

    int t = 1;
    std::cin >> t;
    
    for (int i = 1; i <= t; i++)
    {
        std::cout << "Case #" << i << ": ";
        solve();
    }
    
    return 0;
}