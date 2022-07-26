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

    i64 health = 0LL;
    int potion = 0;
    std::multiset<int> neg;

    for (int i = 0; i < n; ++i)
    {
        if (a[i] >= 0)
            health += a[i], potion++;
        else
        {
            if (health + a[i] >= 0)
                potion++, health += a[i], neg.insert(a[i]);
            else if (neg.size())
            {
                if (*neg.begin() < a[i])
                {
                    health += (a[i] - (*neg.begin()));

                    neg.erase(neg.begin());
                    neg.insert(a[i]);
                }
            }
        }
    }

    std::cout << potion << "\n";
    
    return 0;
}