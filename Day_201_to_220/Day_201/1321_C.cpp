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

    int n;
    std::string s;
    std::cin >> n >> s;

    auto canRemove = [&](int i)
    {
        if (i + 1 < n and s[i] - s[i + 1] == 1)
            return true;
        if (i - 1 >= 0 and s[i] - s[i - 1] == 1)
            return true;

        return false;
    };

    bool can = true;

    while (can)
    {
        std::vector<int> rem;
        std::vector<int> tick(std::size(s));

        for (int i = 0; i < std::size(s); i++)
        {
            if (canRemove(i))
                rem.emplace_back(i);
        }

        if (rem.empty())
            break;
        std::sort(std::begin(rem), std::end(rem), 
            [&](const int &x, const int &y)
            {
                return s[x] > s[y];
            });

        int j = rem[0];
        while (j >= 0 and s[j] == s[rem[0]])
            tick[j] = 1, j--;

        j = rem[0];
        while (j < std::size(s) and s[j] == s[rem[0]])
            tick[j] = 1, j++;

        std::string t;
        for (int i = 0; i < std::size(s); i++)
        {
            if (!tick[i])
                t += s[i];
        }

        std::swap(t, s);
    }

    std::cout << n - std::size(s);    

    return 0;
}