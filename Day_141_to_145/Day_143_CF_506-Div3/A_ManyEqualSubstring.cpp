#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::string s;

    std::cin >> n >> k >> s;

    auto match = [&](int len)
    {
        std::string t1, t2;
        t1 = s.substr(0, len);
        t2 = s.substr(n - len, len);

        return t1 == t2;
    };

    int st = 0;

    for (int len = 1; len < n; len++)
        if (match(len))
            st = len;

    std::string ans = s;
    for (int i = 0; i < k - 1; i++)
        ans += s.substr(st);

    std::cout << ans << "\n";
    
    return 0;
}