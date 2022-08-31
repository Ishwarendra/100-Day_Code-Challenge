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
    std::string s;
    std::cin >> s;

    int n = std::size(s);
    std::string del;

    std::vector<std::vector<int>> pos(26);
    for (int i = 0; i < n; ++i)
    {
        if (pos[s[i] - 'a'].empty())
            del += s[i];

        pos[s[i] - 'a'].emplace_back(i);
    }

    std::sort(std::begin(del), std::end(del), 
        [&](char a, char b)
        {
            if (pos[a - 'a'].empty() or pos[b - 'a'].empty())
                return false;

            return pos[a - 'a'].back() < pos[b - 'a'].back();
        });

    auto find = [&](int x)
    {
        for (int i = 0; i < std::size(del); i++)
            if (del[i] - 'a' == x)
                return i;

        return -10;
    };

    int ub = n;
    for (int i = 0; i < 26; ++i)
    {
        if (pos[i].empty())
            continue;

        int div = find(i) + 1;
        if (div < 0)
            continue;

        if (std::size(pos[i]) % div)
        {
            std::cout << "-1\n";
            return;
        }

        int f = (int) std::size(pos[i]) / div;
        if (pos[i][f - 1] >= ub)
        {
            std::cout << "-1\n";
            return;
        }

        ub = std::min((f < std::size(pos[i]) ? pos[i][f] : INT_MAX), ub);
    }

    auto check = [&](std::string a)
    {
        std::set<int> skip;
        std::string form = a;

        for (char ch : del)
        {
            skip.emplace(ch - 'a');
            for (char temp : a)
            {
                if (skip.count(temp - 'a'))
                    continue;

                form += temp;
            }
        }

        return form == s;
    };

    if (check(s.substr(0, ub)))
        std::cout << s.substr(0, ub) << " " << del << "\n";
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