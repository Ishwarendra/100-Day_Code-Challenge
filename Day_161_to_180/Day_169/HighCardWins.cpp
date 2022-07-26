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
    
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);

    int n;
    std::cin >> n;

    std::vector<int> bessie(n), elsie(n);

    for (int i = 0; i < n; ++i)
        std::cin >> elsie[i];

    std::sort(std::begin(elsie), std::end(elsie));

    for (int i = 1, pos = 0; i <= 2 * n; ++i)
    {
        if (!std::binary_search(std::begin(elsie), std::end(elsie), i))
            bessie[pos++] = i;
    }

    std::sort(std::begin(bessie), std::end(bessie));

    int ans = 0;
    int st = 0, en = n - 1;

    for (int i = n - 1; i >= 0; --i)
    {
        print(elsie[i], bessie[en])
        if (elsie[i] > bessie[en])
            st++;
        else
            en--, ans++;
    }

    std::cout << ans;

    return 0;
}
