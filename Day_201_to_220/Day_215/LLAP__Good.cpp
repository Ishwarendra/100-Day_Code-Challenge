#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution{   
public:
    int lengthOfLongestAP(int a[], int n)
    {
        int max_diff = a[n - 1] - a[0] + 1;
        std::vector<std::vector<int>> dp(n, std::vector<int>(max_diff, 1));

        // i => second element, j => first element
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int d = a[i] - a[j]; // d = common difference
                dp[i][d] = std::max(dp[i][d], dp[j][d] + 1);
            }
        }

        int ans = 0;
        for (int d = 0; d < max_diff; d++)
        {
            for (int i = 0; i < n; i++)
                ans = std::max(ans, dp[i][d]);
        }

        return ans;
    }
    // int lengthOfLongestAP(int a[], int n) 
    // {
    //     if (n <= 2)
    //         return n;

    //     int ans = 0;

    //     for (int i = 0; i < n; ++i)
    //     {
    //         for (int j = i + 1; j < n; ++j)
    //         {
    //             int cur = 2;
    //             int d = a[j] - a[i];
    //             assert(d != 0);

    //             int term = 1;
    //             for (int k = j + 1; k < n; k++)
    //             {
    //                 if ((a[k] - a[j]) % d == 0 and (a[k] - a[j]) / d == term)
    //                 {
    //                     cur++;
    //                     term++;
    //                 }
    //             }

    //             ans = std::max(ans, cur);
    //         }
    //     }

    //     return ans;
    // }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    int A[n];
    for (int i = 0; i < n; ++i)  
        std::cin >> A[i];

    Solution solution;
    std::cout << solution.lengthOfLongestAP(A, n);
    
    return 0;
}