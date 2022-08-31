#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::string s;

    std::cin >> n >> s;

    for (int i = n - 1; i >= (n / 2); --i)  
    {
        if (s[i] == '0')
        {
            std::cout << "1 " << i + 1 << " ";
            std::cout << "1 " << i << "\n";
            return;   
        }
    }

    std::vector<int> ans(4, -1);
    ans[1] = n, ans[3] = n;

    if (s[n / 2 - 1] == '0')
        ans[0] = n / 2, ans[2] = ans[0] + 1;
    else
        ans[0] = n / 2, ans[2] = ans[0] + 1, ans[1] = n - 1;


    for (int i : ans)
        std::cout << i << " ";
    std::cout << "\n";
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