#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s;
    std::cin >> s;

    int n = std::size(s);

    if (n == 1)
    {
        std::cout << (s[0] == '0' or s[0] == 'X' or s[0] == '_' ? "1\n" : "0\n");
        return 0;
    }

    std::string lim_str = "1";
    while (std::size(lim_str) <= n)
        lim_str += '0';

    int limit = std::stoi(lim_str) - 1;

    auto can_make = [&](std::string t)
    {
        if (std::size(t) != std::size(s))
            return false;

        int x = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '_' or s[i] == t[i])
                continue;

            if (s[i] == 'X')
            {
                if (x == -1)
                    x = t[i] - '0';
                else if (x + '0' != t[i])
                    return false;
            }
            else
            {
                if (s[i] != t[i])
                    return false;
            }
        }

        return true;
    };

    int i = 25;
    int ans = 0;

    while (i < limit)
    {
        auto to = std::to_string(i);
        ans += can_make(to);
        i += 25;
    }
    
    std::cout << ans << "\n";

    return 0;
}