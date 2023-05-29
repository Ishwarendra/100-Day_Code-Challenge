#include "bits/stdc++.h"

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
    int q;
    std::cin >> s >> q;

    int n = std::size(s);

    std::array<int, 26> cnt{};
    std::vector dp(26, std::vector<i64>(26));

    for (int i = 0; i < n; i++)
    {
        int end = s[i] - 'a';
        cnt[end]++;
        for (int j = 0; j < 26; j++)
            dp[j][end] += cnt[j];
    }

    while (q--)
    {
        char x, y;
        std::cin >> x >> y;

        std::cout << dp[x - 'a'][y - 'a'] << "\n";
    }
    
    return 0;
}