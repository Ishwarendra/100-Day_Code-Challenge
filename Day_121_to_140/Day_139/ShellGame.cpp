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
    
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    int n;
    std::cin >> n;

    std::vector<int> f(3), s(3), t(3);

    f[0] = 1, s[1] = 1, t[2] = 1;
    int ans1 = 0, ans2 = 0, ans3 = 0;

    for (int i = 0; i < n; ++i)
    {
        int a, b, c;
        std::cin >> a >> b >> c;

        a--, b--, c--;

        std::swap(f[a], f[b]);
        std::swap(s[a], s[b]);
        std::swap(t[a], t[b]);

        ans1 += f[c], ans2 += s[c], ans3 += t[c];
    }

    std::cout << std::max({ans1, ans2, ans3});
    
    return 0;
}