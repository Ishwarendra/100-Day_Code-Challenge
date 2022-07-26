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

    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);

    int k, n;
    std::cin >> k >> n;

    for (int i = 0; i < n; ++i)
    {
        int x;
        std::cin >> x;

        int left = 0, right = 0, tme = 0;

        for (int cur_speed = 1; ; cur_speed++)
        {
            left += cur_speed;
            tme++;

            if (left + right >= k)
            {
                std::cout << tme << "\n";
                break;
            }

            if (cur_speed >= x)
            {
                right += cur_speed;
                tme++;

                if (left + right >= k)
                {
                    std::cout << tme << "\n";
                    break;
                }
            }
        }
    }

    return 0;
}
