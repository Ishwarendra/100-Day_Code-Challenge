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
    
    int n, m;
    std::cin >> n >> m;

    std::string s, t;
    std::cin >> s >> t;

    if (!std::count(std::begin(s), std::end(s), '*'))
    {
        std::cout << (s == t ? "YES\n" : "NO\n");
        return 0;
    }

    std::string first, second;

    bool two = false;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '*')
        {
            two = true;
            continue;
        }

        if (!two)
            first += s[i];
        else
            second += s[i];
    }

    std::reverse(std::begin(second), std::end(second));
    bool can = true;
    for (int i = 0; i < std::size(first); i++)
    {
        if (i >= std::size(t))
        {
            can = false;
            break;
        }
        if (first[i] != t[i])
            can = false;
    }

    for (int i = 0, pos = m - 1; i < std::size(second); i++, pos--)
    {
        if (pos < std::size(first))
        {
            can = false;
            break;
        }

        if (second[i] != t[pos])
            can = false;
    }

    print(first, second)

    if (can)
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
    
    return 0;
}