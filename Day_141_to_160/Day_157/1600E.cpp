#include<bits/stdc++.h>

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

    int ip = 0, is = n - 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[i - 1])
            ip++;
        else
            break;
    }

    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] > a[i + 1])
            is--;
        else
            break;
    }

    auto f = [&](auto f, int st, int en, bool alice)
    {
        if (st > en)
            return !alice;

        if (a[st] <= a[en])
        {
            if ((en - is) % 2 == 0)
                return alice;
            else
                return f(f, st + 1, en, !alice);
        }

        if (a[en] <= a[st])
        {
            if ((ip - st) % 2 == 0)
                return alice;
            else
                return f(f, st, en - 1, !alice);
        }

        return true;
    };

    std::cout << (f(f, 0, n - 1, true) ? "Alice\n" : "Bob\n");

    return 0;
}