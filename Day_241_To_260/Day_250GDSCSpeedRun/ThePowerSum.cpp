#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

template<class T, class G>
T power(T a, G b) 
{
    T res = 1;
    for (; b; b /= 2, a *= a) 
    {
        if (b % 2) 
            res *= a;
    }
    return res;
} 

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int x, n;
    std::cin >> x >> n;

    int ways = 0;
    int num = 0;

    std::function<void(int)> f;
    f = [&](int i)
    {
        if (num >= x or i >= 31)
        {
            ways += num == x;
            return;
        }

        f(i + 1);
        num += power(i, n);
        f(i + 1);
        num -= power(i, n);
    };

    f(1);
    std::cout << ways;
    
    return 0;
}