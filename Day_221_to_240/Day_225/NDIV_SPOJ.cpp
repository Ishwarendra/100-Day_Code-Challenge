#include "bits/stdc++.h"

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
    
    int a, b, n;
    std::cin >> a >> b >> n;

    int ans = 0;
    for (; a <= b; a++)
    {
        int count = 0;
        for (int i = 1; 1LL * i * i <= a; i++)
        {
            if (a % i == 0)
                count += 1 + (i * i != a);

            if (count > n)
                break;
        }

        ans += count == n;
    }

    std::cout << ans;
    
    return 0;
}