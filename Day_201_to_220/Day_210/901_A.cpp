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

    std::vector<int> a(n + 1);
    for (int i = 0; i < n + 1; i++)
        std::cin >> a[i];

    bool can = true;
    std::array<int, 2> id {-1, -1};

    for (int i = 0; i < n; ++i)
    {
        if (a[i] > 1 and a[i + 1] > 1)
        {
            id = {i, i + 1};
            can = false;
        }
    }

    if (can)
    {
        std::cout << "perfect\n";
        return 0;
    }

    std::cout << "ambiguous\n";
    int p = 0;
    for (int i = 0; i <= n; ++i)
    {
        int cnt = 0;
        for (int j = 0; j < a[i]; ++j, ++cnt)
            std::cout << p << " ";

        p += cnt;
    }
    std::cout << "\n";

    bool done = false, do_ = false;
    p = 0;
    for (int i = 0; i <= n; ++i)
    {
        if (i and a[i] > 1 and a[i - 1] > 1 and !done)
            do_ = true;
        int cnt = 0;
        for (int j = 0; j < a[i] - 1; ++j, ++cnt)
            std::cout << p << " ";

        if (do_)
        {
            do_ = false, done = true;
            std::cout << p - 1 << " ";
        }
        else
            std::cout << p << " ";

        p += cnt;
    }

    return 0;
}