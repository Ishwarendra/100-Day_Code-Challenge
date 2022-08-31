#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    std::vector<int> count(21);

    auto getBit = [](int x, int pos)
    {
        return (x >> pos) & 1;
    };

    for (int i = 0; i < n; ++i)
    {
        for (int pos = 0; pos < 21; pos++)
            count[pos] += getBit(a[i], pos);
    }

    i64 ans = 0;
    bool can = true;

    // ai * bi > af * bf
    while (can)
    {
        can = false;

        int temp = 0;
        for (int i = 0; i < 21; i++)
        {
            if (count[i])
            {
                can = true;
                count[i]--;
                temp |= (1 << i);
            }
        }

        ans += 1LL * temp * temp;
    }

    std::cout << ans << "\n";
    
    return 0;
}