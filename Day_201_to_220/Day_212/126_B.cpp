#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

std::string no = "Just a legend";

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    int n = std::size(s);

    std::vector<int> pi(n);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 and s[i] != s[j])
            j = pi[j - 1];

        pi[i] = j + (s[i] == s[j]);
    }

    auto check = [&](int x)
    {
        if (x == 0)
            return false;

        for (int i = 0; i < n - 1; i++)
            if (pi[i] == x)
                return true;

        return false;
    };

    if (check(pi[n - 1]))
        std::cout << s.substr(0, pi[n - 1]);
    else if (check(pi[pi[n - 1] - 1]))
        std::cout << s.substr(0, pi[pi[n - 1] - 1]);
    else
        std::cout << no;

    return 0;
}