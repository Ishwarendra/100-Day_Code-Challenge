#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    k--;
    int leftPos = k - 1, rightPos = k + 1;
    int can = 1;

    while (can) 
    {
        can = 0;
        int i = leftPos, j = rightPos;

        i64 sum = 0;
        while (i >= 0)
        {
            sum += a[i--];
            if (sum >= 0)
            {
                leftPos = i;
                a[k] += sum;
                can = 1;
                sum = 0;
            }

            if (sum + a[k] < 0)
            {
                i++;
                break;
            }
        }

        sum = 0;
        while (j < n)
        {
            sum += a[j++];
            if (sum >= 0)
            {
                rightPos = j;
                a[k] += sum;
                can = 1;
                sum = 0;
            }

            if (sum + a[k] < 0)
            {
                j--;
                break;
            }
        }

        if (i < 0 or j >= n)
        {
            std::cout << "YES\n";                                   
            return;
        }
    }
    
    if (leftPos < 0 or rightPos >= n)
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
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