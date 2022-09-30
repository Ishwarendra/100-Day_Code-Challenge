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

    std::vector<int> q(n - 1);
    for (int i = 0; i < n - 1; i++)
        std::cin >> q[i];

    int min_a = 1, max_a = n;
    i64 sum = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        sum += q[i];
        
        if (sum > 0)
        {
            // a + sum <= n
            max_a = std::min<i64>(max_a, n - sum);
        }
        else if (sum < 0)
        {
            // a + sum >= 1
            min_a = std::max<i64>(min_a, 1LL - sum);
        }   
        else
        {
            std::cout << "-1\n";
            std::exit(0);
        }

        if (max_a < min_a or max_a <= 0 or min_a > n)
        {
            std::cout << "-1\n";
            std::exit(0);
        }
    }

    std::vector<int> a(n, min_a);
    for (int i = 1; i < n; ++i)
        a[i] = a[i - 1] + q[i - 1];

    if (std::size(std::set(std::begin(a), std::end(a))) < n)
        std::cout << "-1\n";
    else
    {
        for (int i = 0; i < n; ++i)
            std::cout << a[i] << " \n"[i == n - 1];
    }
    
    return 0;
}