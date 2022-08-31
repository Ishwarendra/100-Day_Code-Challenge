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

    int sum = 0;
    for (char ch : s)
        sum += ch - '0';

    auto possible = [&](int x)
    {
        int cur = 0, cnt = 0;
        for (char ch : s)
        {
            cur += ch - '0';
            if (cur > x)
                return false;

            if (cur == x)
            {
                cnt++;
                cur = 0;
            }
        }

        return cnt > 1 and (cur == x or cur == 0);
    };

    for (int i = 0; i <= sum; i++)
    {
        if (possible(i))
        {
            std::cout << "YES\n";
            return 0;
        }
    }
    
    std::cout << "NO\n";

    return 0;
}