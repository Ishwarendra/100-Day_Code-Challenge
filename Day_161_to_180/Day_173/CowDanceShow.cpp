#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);

    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    int left = 1, right = n, ans = 0;

    auto good = [&](int mid)
    {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        int last = 0;

        for (int i = 0; i < mid - 1; i++)
            pq.push(a[i]);

        for (int i = mid - 1; i < n; ++i)
        {
            pq.push(last + a[i]);

            last = pq.top();
            pq.pop();
        }

        while (!pq.empty())
        {
            last = std::max(last, pq.top());
            pq.pop();
        }

        return last <= k;
    };

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (good(mid))
            ans = mid, right = mid - 1;
        else
            left = mid + 1;
    }

    std::cout << ans << "\n";
    
    return 0;
}
