#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s;
    std::cin >> s;

    int n = std::size(s);
    
    auto find = [&](char ch, int st)
    {
        int i = st;
        for (; i < n; i++)
        {
            if (s[i] != ch)
                return i; 
        }

        return i;
    };

    auto count = [&](char ch)
    {
        return std::count(std::begin(s), std::end(s), ch);
    };

    int st = 0;
    for (char ch : {'a', 'b', 'c'})
    {
        int en = find(ch, st);
        if (en - st == 0)
        {
            std::cout << "NO\n";
            return 0;
        }
        st = en;
    }

    if (st != n or count('c') != count('a') and count('c') != count('b'))
        std::cout << "NO\n";
    else
        std::cout << "YES\n";

    return 0;
}