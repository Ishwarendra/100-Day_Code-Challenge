#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

void solve()
{
    std::string yes = "Spell!", no = "Nothing.";

    std::string s;
    std::cin >> s;

    int n = std::size(s);
    std::set<char> vowels({'a', 'e', 'i', 'o', 'u'});
    std::vector<int> pos;

    for (int i = 0; i < n; ++i)
        if (vowels.count(s[i]))
            pos.push_back(i);

    if (std::size(pos) < 5)
    {
        std::cout << no << "\n";
        return;
    }

    int sz = std::size(pos);
    for (int i = 0; i < sz - 4; ++i)
    {
        std::string start = s.substr(pos[i], pos[i + 1] - pos[i] + 1);
        for (int j = i + 3; j < sz - 1; j++)
        {
            std::string end = s.substr(pos[j], pos[j + 1] - pos[j] + 1);

            if (start == end)
            {
                std::cout << yes << "\n";
                return;
            }
        }
    }

    std::cout << no << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    for (int i = 1; i <= t; i++)
    {
        std::cout << "Case #" << i << ": ";
        solve();
    }
    
    return 0;
}