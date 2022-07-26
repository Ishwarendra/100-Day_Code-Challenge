#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

int void(int a, std::vector<int> &b, int c)
{
    std::vector<std::pair<int, int>> A(n);
    for (int i = 0; i < n; ++i)
    {
        A[i].first = a[i];
        A[i].second = i;
    }

    std::sort(std::begin(A), std::end(A));

    int left = 1, right = n;
    int ans = n;

    auto good = [&](int mid)
    {
        int smallest_essence = A[n - mid].first;

        std::vector<int> vis(n);
        for (int i = 0; i < n; i++)
        {
            if (a[i] >= smallest_essence)
                vis[i] = 1;
        }

        
    };

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (good(mid))
            ans = mid, right = mid - 1;
        else
            left = mid + 1;
    }

    return ans;
}

int main()
{
    return 0; 
}    