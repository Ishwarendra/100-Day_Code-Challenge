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
    
    std::map<int, int, std::greater<>> m;
    auto pf = [&](int x)
    {
        std::vector<int> a;
        for (int i = 2; i * i <= x; i++)
        {
            while (x % i == 0)
                x /= i, a.emplace_back(i);
        }

        if (x > 1)
            a.emplace_back(x);

        return a;
    };

    for (int i = 0; i < n; ++i)
    {
        int cur = s[i] - '0';
        for (int j = 2; j <= cur; j++)
        {
            for (auto num : pf(j))
                m[num]++;
        }
    }
    
    for (auto [num, f] : m)
    {
        for (int i = num - 1; i >= 2; i--)
        {
            for (auto x : pf(i))
            {
                m[x] -= f;
                if (m[x] == 0)
                    m.erase(x);
            }
        }
    }

    for (auto [num, f] : m)
    {
        while (f-- > 0)
            std::cout << num;
    }
    
    return 0;
}