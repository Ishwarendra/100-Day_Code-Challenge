#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(...) 1;
#define print(...) 1;
#endif

constexpr int N = 1001;
constexpr int inf = 1e9;
int n, m, K;
std::string s, t;

int dp[N][N][11][2];

int f(int i, int j, int k, int ongoing)
{
    if (i == n or j == m)
        return (k == 0 ? 0 : -inf);

    if (k == 0)
        return 0;

    int &cur = dp[i][j][k][ongoing];
    if (cur != -1)
        return cur;

    cur = 0;
    // ignore char of s or t and then find the answer
    cur = std::max({cur, f(i + 1, j, k - ongoing, 0), f(i, j + 1, k - ongoing, 0)});

    if (s[i] == t[j])
    {
        // if you are still choosing then continue choosing for same substr
        cur = std::max(cur, 1 + f(i + 1, j + 1, k, 1));

        // if you haven't been choosing now is the right time to start choosing :x:
        // choose and end :check:
        cur = std::max(cur, 1 + f(i + 1, j + 1, k - 1, 1));
    }

    return cur;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m >> K >> s >> t;

    memset(dp, -1, sizeof dp);

    std::cout << f(0, 0, K, 0) << "\n";

    return 0;
}