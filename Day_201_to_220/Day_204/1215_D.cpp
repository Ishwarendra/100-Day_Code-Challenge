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

    auto bicarp = [&](char ch)
    {
        int mono = 1;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '?')
            {
                if (mono)
                    s[i] = (i < n / 2 ? ch : '9' - ch + '0');
                else
                    s[i] = (i >= n / 2 ? ch : '9' - ch + '0');
                mono ^= 1;
            }
        }

        int sum_half = 0;
        for (int i = 0; i < n / 2; ++i)
        {
            if (s[i] != '?')
                sum_half += s[i] - '0';
        }

        int sum_next = 0;
        int can = 0;
        for (int i = n / 2; i < n; i++)
        {
            if (s[i] != '?')
                sum_next += s[i] - '0';
            else
                can += 9;
        }

        return (sum_half >= sum_next and can >= sum_half - sum_next);
    };

    if (bicarp('9') or bicarp('0'))
        std::cout << "Bicarp\n";
    else
        std::cout << "Monocarp\n";

    return 0;
}