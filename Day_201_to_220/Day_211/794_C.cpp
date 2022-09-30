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
    
    std::string s, t;
    std::cin >> s >> t;

    int n = std::size(s);

    std::multiset<char> small;
    std::multiset<char, std::greater<>> big;

    for (int i = 0; i < n; ++i)
    {
        small.emplace(s[i]);
        big.emplace(t[i]);
    }

    while (std::size(small) != (n + 1) / 2)
        small.erase(--std::end(small));
    while (std::size(big) != n / 2)
        big.erase(--std::end(big));

    int turn = 1;
    std::string ans(n, '!');

    int st = 0, en = n - 1;
    while (!small.empty() or !big.empty())
    {
        if (turn)
        {
            // Enemy has bigger than me
            if (!big.empty() and *std::begin(big) > *std::begin(small))
            {
                ans[st++] = *std::begin(small);
                small.erase(std::begin(small));
            }
            else
            {
                ans[en--] = *(--std::end(small));
                small.erase(--std::end(small));
            }
        }
        else
        {
            // Small got big 
            if (!small.empty() and *std::begin(small) >= *std::begin(big))
            {
                ans[en--] = *(--std::end(big));
                big.erase(--std::end(big));
            }
            else
            {
                ans[st++] = *std::begin(big);
                big.erase(std::begin(big));
            }
        }

        turn ^= 1;
    }


    std::cout << ans;
    
    return 0;
}