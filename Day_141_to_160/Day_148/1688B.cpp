#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> odd, even;

    for (int i = 0; i < n; ++i)
    {
        int x;
        std::cin >> x;

        (x & 1 ? odd : even).push_back(x);
    }

    if (odd.size())
        std::cout << even.size() << "\n";
    else
    {
        int min = 32;
        for (int i : even)
        {
            int cnt = 0;
            while (i % 2 == 0)
                i /= 2, cnt++;

            min = std::min(min, cnt);
        }

        std::cout << min + (n - 1) << '\n';
    }
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