#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);

    int n;
    std::string s, t;
    std::cin >> n >> s >> t;

    int add = 0, ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] != t[i])
            add |= 1;
        else
        {
            ans += add;
            add = 0;
        }
    }

    std::cout << ans;
    
    return 0;
}
