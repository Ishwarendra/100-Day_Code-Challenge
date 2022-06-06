#include<bits/stdc++.h>

#ifdef LOCAL
    #include <F:\CPP\Debug\debug.h> 
#else
    #define trace(x...) 1;
    #define print(x...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s;
    std::cin >> s;
    
    if (s == std::string(1, '0'))
        return 0;
    
    int n = s.size();
    std::vector<i64> dp(n + 1);
    
    dp[0] = 1;
    dp[1] = 1;
    
    for (int i = 2; i < n + 1; i++)
    {
        if (s[i - 1] != '0')
            dp[i] = dp[i - 1];
        
        int doubleDig = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
        
        if (s[i - 2] != '0' and doubleDig <= 26)
            dp[i] += dp[i - 2];
    }
    
    std::cout << dp[n] << "\n";
    main();
    
    return 0;
}