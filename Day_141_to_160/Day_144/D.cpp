#include <bits/stdc++.h>

#define LOCAL

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);

    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    auto getBit = [&](int x, int pos)
    {
        return (x >> pos) & 1;
    };

    for (int i = 0; i < 30; i++)
    {
        std::vector<int> on_bits(1);

        for (int j = 0; j < n; ++j)
        {
            if (getBit(a[j], i))
                on_bits.push_back(j + 1);
        }

        if (on_bits.size() > 2)
        {
            on_bits.back() = n;
            print(i, on_bits)

            std::cout << "YES\n" << on_bits.size() - 1 << "\n";

            for (int i = 1; i < on_bits.size(); i++)
                std::cout << on_bits[i - 1] + 1 << " " << on_bits[i] << "\n";

            return;
        }
    }

    std::cout << "NO\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while(t--)
        solve();
    
    return 0;
}