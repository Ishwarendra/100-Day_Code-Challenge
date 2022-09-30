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
    
    int n;
    std::cin >> n;

    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++)
    {
        char ch;
        std::cin >> ch;
        std::cin >> a[i];
    }

    std::reverse(std::begin(a), std::end(a));
    std::vector<std::string> ans(n);
    ans[0] = a[0];

    for (int i = 1; i < n; i++)
    {
        int m = std::min<int>(std::size(a[i]), std::size(ans[i - 1]));
        int end = m - 1;

        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == ans[i - 1][j])
                continue;
            else if (a[i][j] < ans[i - 1][j])
                end = std::size(a[i]) - 1;
            else
                end = j - 1;

            break;
        } 

        std::string cur;
        for (int j = 0; j <= end; j++)
            cur += a[i][j];
            
        ans[i] = cur;
    }

    std::reverse(std::begin(ans), std::end(ans));

    for (auto s : ans)
        std::cout << "#" << s << "\n";
    
    return 0;
}