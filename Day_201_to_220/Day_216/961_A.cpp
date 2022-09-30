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
    
    int m, n;
    std::cin >> m >> n;

    std::map<int, int> freq;
    int ans = 0;
    for (int i = 0; i < n; i++)  
    {
        int x;
        std::cin >> x;

        freq[x]++;
        if (std::size(freq) == m)
        {
            for (int i = 1; i <= m; ++i)
            {
                freq[i]--;

                if (freq[i] == 0)
                    freq.erase(i);
            }
            ans++;
        }
    }

    std::cout << ans;
    
    return 0;
}