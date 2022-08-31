#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, l;
    std::cin >> n >> l;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    int i = 0, j = n - 1;

    int v1 = 1, v2 = 1;
    double x1 = 0, x2 = l;

    double t = 0;

    while (i <= j)
    {
        double t1 = 1.0 * (a[i] - x1) / v1;
        double t2 = 1.0 * (x2 - a[j]) / v2;

        if (t1 == t2)
        {
            x1 = a[i], x2 = a[j];
            i++, j--;
            t += t1;
            v1++, v2++;
        }
        else if (t1 < t2)
        {
            t += t1;
            x1 = a[i++];
            x2 -= v2 * t1;
            v1++;
        }
        else
        {
            t += t2;
            x2 = a[j--];
            x1 += t2 * v1;
            v2++;
        }   
    }

    t += abs(x1 - x2) / (v1 + v2);

    std::cout << t << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << std::fixed;
    std::cout << std::setprecision(7); 

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}