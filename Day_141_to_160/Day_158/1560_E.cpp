#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

void solve()
{
    std::string s;
    std::cin >> s;

    int n = std::size(s);
    std::vector<int> last(26), cnt(26);

    for (int i = 0; i < n; ++i)  
    {
        last[s[i] - 'a'] = i;
        cnt[s[i] - 'a']++;
    }
    std::set<char> distinct(std::begin(s), std::end(s));
    std::string to_del;

    for (char ch : distinct)
        to_del += ch;

    std::sort(std::begin(to_del), std::end(to_del), 
        [&](char &a, char &b)
        {
            return last[a - 'a'] < last[b - 'a'];
        });

    int len = 0;
    for (int i = 0; i < std::size(to_del); i++)
    {
        if (cnt[to_del[i] - 'a'] % (i + 1) != 0)
        {
            std::cout << "-1\n";
            return;
        }

        len += cnt[to_del[i] - 'a'] / (i + 1);
    }

    std::string t = s.substr(0, len);
    std::string form;
    distinct.clear();
    int pos = 0;

    len = std::size(to_del);
    while (len--)
    {
        for (int i = 0; i < std::size(t); ++i)
        {
            if (!distinct.count(t[i]))
                form += t[i];
        }

        distinct.emplace(to_del[pos++]);
    }
    
    if (form == s)
        std::cout << t << " " << to_del << "\n";
    else
        std::cout << "-1\n";
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