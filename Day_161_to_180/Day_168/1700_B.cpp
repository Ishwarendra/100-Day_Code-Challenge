#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

std::string sub(std::string &a, std::string &b)
{
    std::string ans;
    b = '0' + b;

    int n = std::size(a);
    for (int i = n - 1; i > 0; --i)
    {
        if (a[i] >= b[i])
            ans += a[i] - b[i] + '0';
        else
        {
            ans += 10 + a[i] - b[i] + '0';
            a[i - 1]--;
        }
    }

    std::reverse(std::begin(ans), std::end(ans));
    return ans;
}

void solve()
{
    int n;
    std::string s;

    std::cin >> n >> s;

    std::string ans;

    if (s[0] != '9')
    {
        for (int i = 0; i < n; ++i)
            ans += '9' + '0' - s[i];
    }
    else
    {   
        ans = std::string(n + 1, '2');
        ans[0] = '1', ans[n] = '1';

        ans = sub(ans, s);
    }

    std::cout << ans << "\n";
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