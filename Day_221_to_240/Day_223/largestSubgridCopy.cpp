#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int largestSubgrid(std::vector<std::vector<int>> &grid, int maxSum)
{
    int n = grid.size();
    if (n == 0)
        return 0;

    std::vector<std::vector<long long>> pref(n + 5, std::vector<long long>(n + 5));
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= n; j++)
        {
            pref[i][j] = grid[i - 1][j - 1] + pref[i - 1][j] 
                        + pref[i][j - 1] - pref[i - 1][j - 1];
        }
    }

    auto maxSumOfSize = [&](int sz)
    {
        long long ans = 0;
        for (int i = 1; i <= n - sz + 1; i++)
        {
            for (int j = 1; j <= n - sz + 1; j++)
            {
                long long cur_sum = pref[i + sz - 1][j + sz - 1] + pref[i - 1][j - 1];
                cur_sum -= pref[i - 1][j + sz - 1] + pref[i + sz - 1][j - 1];

                ans = std::max(ans, cur_sum);
            }
        }
        
        return ans;
    };
    
    int left = 1, right = n;
    int ans = 0;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        long long sum = maxSumOfSize(mid);

        if (sum <= maxSum)
            ans = mid, left = mid + 1;
        else
            right = mid - 1; 
    }

    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
        
    int n, maxSum;
    std::cin >> n >> maxSum;

    std::vector grid(n, std::vector(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            std::cin >> grid[i][j];

    std::cout << largestSubgrid(grid, maxSum) << '\n';
    
    return 0;
}