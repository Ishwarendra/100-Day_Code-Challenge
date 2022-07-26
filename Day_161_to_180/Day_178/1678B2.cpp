#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

int b1(const std::string &s)
{
    int n = std::size(s);

    int cnt = 1;
    std::vector<int> a, odd;
 
    for (int i = 1; i < n; i++)  
    {
        if (s[i] != s[i - 1])
        {
            a.emplace_back(cnt);
            if (cnt % 2)
                odd.push_back((int) std::size(a) - 1);
 
            cnt = 1;
        }
        else
            cnt++;
    }
 
    a.emplace_back(cnt);
    if (cnt % 2)
        odd.push_back((int) std::size(a) - 1);
 
    cnt = 0;
    for (int i = 1; i < std::size(odd); i += 2)
        cnt += odd[i] - odd[i - 1];
 
    return cnt;
}

void solve()
{
    int n;
    std::string s;
    std::cin >> n >> s;

    constexpr int inf = 1e9;
    int op = b1(s);
    std::vector<int> dp(2, 1);

    if (s[0] == s[1])
        dp[s[0] == '0'] = inf;

    for (int i = 2; i < n; i += 2)
    {
        std::vector<int> ndp(2, inf);

        if (s[i] == s[i + 1])
        {
            if (s[i] == '1')
                ndp[1] = std::min(dp[1], dp[0] + 1);
            else
                ndp[0] = std::min(dp[0], dp[1] + 1);
        }
        else
        {
            ndp[0] = std::min(dp[0], dp[1] + 1);
            ndp[1] = std::min(dp[0] + 1, dp[1]);
        }

        std::swap(ndp, dp);
    }

    std::cout << op << ' ' << std::min(dp[0], dp[1]) << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--)
        solve();

    return 0;
}