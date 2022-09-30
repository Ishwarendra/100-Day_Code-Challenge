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
    
    std::string s;
    std::cin >> s;
    int n = std::size(s);

    for (int i = 0; i < n; ++i)
        s[i] = '0' + ((s[i] - '0') % 3);

    int ans = 0;

    std::vector<int> pos(1, -1);
    for (int i = 0; i < n; i++)
    {
        if ((s[i] - '0') % 3 == 0)
            pos.emplace_back(i);
    }
    pos.emplace_back(n);

    std::sort(std::begin(pos), std::end(pos));

    ans += std::size(pos);
    ans -= 2;

    for (int i = 1; i < std::size(pos); ++i)
    {
        int st = pos[i - 1] + 1;
        for (int j = pos[i - 1] + 1; j < pos[i]; j++)
        {
            int sum = 0;
            for (int k = j; k >= st; k--)
            {
                sum += s[k] - '0';
                if (sum % 3 == 0)
                {
                    st = j + 1;
                    ans++;
                    break;
                }
            }            
        }
    }

    std::cout << ans;
    
    return 0;
}