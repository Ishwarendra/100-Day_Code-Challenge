#include <bits/stdc++.h>
using namespace std;

#define LOCAL 1

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(...) 1;
#define print(...) 1;
#endif

int isMatch(const std::string a, const std::string b) 
{
    int n = a.size(), m = b.size();

    std::vector<int> dp(m + 1);
    dp[0] = 1;

    for (int i = 1; i <= m; i++)
    {
        if (b[i - 1] == '*')
            dp[i] = 1;
        else
            break;
    }
    
    for (int i = 1; i <= n; i++)    
    {
        std::vector<int> ndp(m + 1);

        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1] or b[j - 1] == '?')
                ndp[j] = dp[j - 1];
            else if (b[j - 1] == '*')
                ndp[j] = dp[j] | ndp[j - 1];
        }

        std::swap(ndp, dp);
        // print(dp);
    }

    return dp[m];
}

int main()
{
    std::string a, b;
    std::cin >> a >> b;

    std::cout << isMatch(a, b);
    return 0;
}