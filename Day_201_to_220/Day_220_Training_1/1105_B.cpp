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
    
    int n, k;
    std::string s;
    std::cin >> n >> k >> s;

    auto get = [&](char ch)
    {
        int cnt = 0, ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != ch)
            {
                if (cnt >= k)
                    ans += cnt / k;
                cnt = 0;
            }
            else
                cnt++;
        }

        if (cnt >= k)
            ans += cnt / k;

        return ans;
    };  

    int ans = 0;
    for (char ch = 'a'; ch <= 'z'; ch++)
        ans = std::max(ans, get(ch));

    std::cout << ans;
    
    return 0;
}