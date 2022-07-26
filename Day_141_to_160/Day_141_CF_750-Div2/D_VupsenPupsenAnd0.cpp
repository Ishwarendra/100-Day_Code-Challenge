#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

using i64 = long long;

i64 gcd(i64 a, i64 b, i64 &x0, i64 &y0)
{
    if (b == 0)
    {
        x0 = 1, y0 = 0;
        return a;
    }

    i64 x, y;
    i64 d = gcd(b, a % b, x, y);

    x0 = y;
    y0 = x - y * (a / b);

    return d;
}

bool get_one_solution(i64 a, i64 b, i64 c, i64 &x0, i64 &y0, i64 &g)
{
    g = gcd(abs(a), abs(b), x0, y0);

    if (c % g == 1)
        return false;

    x0 *= c / g;
    y0 *= c / g;

    if (a < 0)
        x0 = -x0;
    if (b < 0)
        y0 = -y0;

    return true;
}

void shift(i64 & x, i64 & y, i64 a, i64 b, i64 k)
{
    x += k * b;
    y -= k * a;
}

i64 get_all_in_range(i64 a, i64 b, i64 c, i64 min_x, i64 max_x, i64 min_y, i64 max_y)
{
    i64 x, y, g;

    if (!get_one_solution(a, b, c, x, y, g))
        return 0;

    a /= g;
    b /= g;

    i64 sign_a = a > 0 ? +1 : -1;
    i64 sign_b = b > 0 ? +1 : -1;

    shift(x, y, a, b, (min_x - x) / b);
    if (x < min_x)
        shift(x, y, a, b, sign_b);
    if (x > max_x)
        return 0;
    i64 lx1 = x;

    shift(x, y, a, b, (max_x - x) / b);
    if (x > max_x)
        shift(x, y, a, b, -sign_b);
    i64 rx1 = x;

    shift(x, y, a, b, -(min_y - y) / a);
    if (y < min_y)
        shift(x, y, a, b, -sign_a);
    if (y > max_y)
        return 0;
    i64 lx2 = x;

    shift(x, y, a, b, -(max_y - y) / a);
    if (y > max_y)
        shift(x, y, a, b, sign_a);
    i64 rx2 = x;
    if (lx2 > rx2)
        std::swap(lx2, rx2);

    i64 lx = std::max(lx1, lx2);
    i64 rx = std::min(rx1, rx2);

    if (lx > rx)
        return 0;

    return ((rx - lx) / abs(b)) + 1;
}

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
        int prob = 0;

        i64 a1 = a[i], b1 = a[i + 1], c1 = a[i + 2];

        for (int k = 10; k <= 10; k++)
        {
            if (k == 0)
                continue;

            i64 c = c1 * k;
            i64 x0, y0, g;
            i64 f = -1e9;
            if (get_one_solution(a1, b1, c, x0, y0, g))
            {
                int sa = (a1 > 0 ? 1 : -1);
                int sb = (b1 > 0 ? 1 : -1);

                i64 fmx = std::max(((y0 + 1e4) * g + a1 - sa) / a1, ((1e4 + x0) * g + b1 - sb) / b1);
                i64 fmn = std::min((y0 - 1e4) * g / a1, (-1e4 - x0) * g / b1);

                f = std::min(fmn, fmx);
            }

            if (f == -1e9)
                continue;

            assert(a1 * x0 + b1 * y0 == c);

            shift(x0, y0, a1, b1, f);

            if (x0 == 0)
                shift(x0, y0, a1, b1, 1);
            if (y0 == 0)
                shift(x0, y0, a1, b1, 2);

            assert(x0 != 0 and y0 != 0);
            assert(a1 * x0 + b1 * y0 == c);

            b[i] = x0, b[i + 1] = y0;
            b[i + 2] = -k;


            i64 sum = 0;
            for (int i = 0; i < n; ++i)
                sum += a[i] * b[i];

            assert(sum == 0);

            for (int id = 0; id < n; ++id)
                std::cout << b[id] << " \n"[id == n - 1];

            return;
        }

        assert(false);
        // print(prob)
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