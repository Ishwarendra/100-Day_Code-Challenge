#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

using i64 =  long long;

template <typename T>
struct Rect
{
    T bl_x, bl_y, tr_x, tr_y;

    Rect() : bl_x(0), bl_y(0), tr_x(0), tr_y(0) {}

    Rect(T x1, T y1, T x2, T y2) :
        bl_x(x1), bl_y(y1), tr_x(x2), tr_y(y2) {}

    friend std::istream & operator >>(std::istream & is, Rect & r)
    {
        is >> r.bl_x >> r.bl_y >> r.tr_x >> r.tr_y;
        return is;
    }

    T area() const
    {
        return (tr_x - bl_x) * (tr_y - bl_y);
    }

    bool between(const T x, const T l, const T r)
    {
        return (x >= std::min(l, r) and x <= std::max(l, r));
    }

    T intersection_area(const Rect &r) const
    {
        T l = std::max(T(0), std::min(tr_x, r.tr_x) - std::max(bl_x, r.bl_x));
        T w = std::max(T(0), std::min(tr_y, r.tr_y) - std::max(bl_y, r.bl_y));

        return l * w;
    }

    T intersection_area(const std::vector<Rect> a) const
    {
        assert(!a.empty());
        T l = 0, w = 0;

        T x1 = bl_x, x2 = tr_x, y1 = bl_y, y2 = tr_y;

        for (auto &r : a)
        {
            x1 = std::max(x1, r.bl_x);
            y1 = std::max(y1, r.bl_y);
            x2 = std::min(x2, r.tr_x);
            y2 = std::min(y2, r.tr_y);
        }

        l = std::max(l, x2 - x1);
        w = std::max(w, y2 - y1);

        return l * w;
    }

    bool inside(const T x, const T y)
    {
        return between(x, bl_x, tr_x) and between(y, bl_y, tr_y);
    }
};

void solve()
{
    Rect<i64> a, b, c;
    std::cin >> a >> b >> c;

    i64 area = a.area() - a.intersection_area(b) - a.intersection_area(c);
    area += a.intersection_area({b, c});

    if (area == 0)
        std::cout << "NO\n";
    else
        std::cout << "YES\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;

    while (t--)
        solve();

    return 0;
}