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

    std::vector<int> x(n), y(n);
    for (int i = 0; i < n; i++)
        std::cin >> x[i] >> y[i];

    auto shuffle = [&]()
    {
        std::vector<std::pair<int, int>> a(n);
        for (int i = 0; i < n; i++)
            a[i] = {x[i], y[i]};

        std::random_shuffle(std::begin(a), std::end(a));

        for (int i = 0; i < n; i++)
            x[i] = a[i].first, y[i] = a[i].second;
    };

    std::function<bool(int)> cmon = [&](int cnt)
    {
        shuffle();

        auto slope = [&](int i, int j)
        {
            int num = y[j] - y[i];
            int den = x[j] - x[i];

            if (1LL * num * den < 0)
                num = -std::abs(num), den = std::abs(den);
            else
                num = std::abs(num), den = std::abs(den);

            int g = std::gcd(num, den);
            num /= g, den /= g;

            return std::pair<int, int>(num, den);
        };

        std::map<std::pair<int, int>, int> m;
        for (int i = 1; i < n; i++)
        {
            auto [num, den] = slope(0, i);
            m[{num, den}]++;
        }

        std::pair<int, int> max;
        int max_f = 0;
        for (auto [p, f] : m)
        {
            if (f > max_f)
                max_f = f, max = p;
        }

        std::vector<int> done(n);
        done[0] = 1;

        for (int i = 1; i < n; i++)
        {
            if (slope(0, i) == max)
                done[i] = 1;
        }

        int first = -1, second = -1;
        for (int i = 1; i < n; ++i)
        {
            if (!done[i] and first == -1)
                first = i;
            else if (!done[i])
            {
                second = i;
                break;
            }
        }

        if (first == -1 or second == -1)
        {
            std::cout << "YES\n";
            return true;
        }

        done[first] = 1, done[second] = 1;
        max = slope(first, second);

        for (int i = second + 1; i < n; i++)
        {
            if (done[i])
                continue;

            if (max == slope(first, i))
                done[i] = 1;
        }

        if (std::accumulate(std::begin(done), std::end(done), 0) != n)
        {
            if (cnt < 10)
            {
                bool ans = cmon(++cnt);
                if (ans)
                    return true;
            }
        }
        else
        {
            std::cout << "YES\n";
            return true;
        }

        return false;
    };

    bool done = cmon(0);

    if (!done)
        std::cout << "NO\n";

    return 0;
}