#include <bits/stdc++.h>

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

    if (n % 2 == 0)
    {
        std::vector<int> b(n);

        int i = 0, j = n - 1;

        while (j > i)
        {
            b[i] = -a[j];
            b[j] = a[i];
            i++, j--;
        }

        i64 sum = 0;
        for (int i = 0; i < n; ++i)
            sum += a[i] * b[i];

        assert(sum == 0);

        for (int i = 0; i < n; ++i)
            std::cout << b[i] << " \n"[i == n - 1];

        return;
    }
    else
    {
        std::vector<int> b(n);

        int i = 0, j = n - 1;

        while (j - i > 2)
        {
            b[i] = -a[j];
            b[j] = a[i];
            i++, j--;
        }

        std::vector<int> id {0, 1, 2};

        do
        {
            b[i + id[0]] = -a[i + id[1]];
            b[i + id[1]] = a[i + id[0]] - a[i + id[2]];
            b[i + id[2]] = a[i + id[1]];

            bool ok = true;

            for (int j = 0; j < 3; j++)
                if (b[i + id[j]] == 0)
                    ok = false;

            if (ok)
                break;

        } while (std::next_permutation(id.begin(), id.end()));

        if (a[i] == a[i + 1] and a[i + 1] == a[i + 2])
            b[i] = b[i + 1] = 1, b[i + 2] = -2;

        i64 sum = 0;
        for (i = 0; i < n; ++i)
        {
            assert(b[i] != 0);
            sum += a[i] * b[i];
        }

        assert(sum == 0);

        for (int _ = 0; _ < n; ++_)
            std::cout << b[_] << " \n"[_ == n - 1];

        return;
    }
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