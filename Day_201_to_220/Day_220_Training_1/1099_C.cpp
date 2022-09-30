#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s;
    int k;
    std::cin >> s >> k;

    int len = 0, flake = 0, candy = 0;
    for (auto ch : s)
    {
        if (ch == '*')
            flake++;
        else if (ch == '?')
            candy++;
        else
            len++;
    }

    if (len > k and len - candy - flake > k)
        std::cout << "Impossible\n";
    else if (len < k)
    {
        if (flake == 0)
            std::cout << "Impossible\n";
        else
        {
            int pos = std::find(std::begin(s), std::end(s), '*') - std::begin(s);
            std::set<int> must;
            for (int i = 0; i < std::size(s); i++)
            {
                if (i + 1 < std::size(s) and (s[i + 1] != '?' and s[i + 1] != '*'))
                    must.emplace(i);
                else if (i + 1 == std::size(s))
                    must.emplace(i);
                else
                    i++;
            }
            
            int need = k - (int)std::size(must);
            for (int i = 0; i < std::size(s); ++i)
            {
                if (must.count(i))
                    std::cout << s[i];
                else
                {
                    if (i + 1 < std::size(s) and s[i + 1] == '*')
                    {
                        while (need-- > 0)
                            std::cout << s[i];
                    }
                }
            }
        }
    }
    else 
    {
        std::string ans;
        for (int i = 0; i < (int)std::size(s); ++i)
        {
            if (len > k)
            {
                if (i + 1 < (int)std::size(s) and (s[i + 1] == '?' or s[i + 1] == '*'))
                    len--, i++;
                else
                    ans += s[i];
            }
            else
            {
                if (s[i] != '?' and s[i] != '*')
                    ans += s[i];
            }
        }

        std::cout << ans;
    }
    
    return 0;
}