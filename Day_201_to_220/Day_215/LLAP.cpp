#include <bits/stdc++.h>
using namespace std;

int f(int i, int n, int A[], int diff, int preI, vector<vector<int>> &dp)
{
    if (i == n)
        return 0;
    if (dp[i][preI + 1] != -1)
        return dp[i][preI + 1];
    int j, k, ma = 0;
    for (j = i; j < n; j++)
    {
        if (preI == -1)
        {
            for (k = j + 1; k < n; k++)
            {
                diff = A[k] - A[j];
                ma = max(ma, 1 + f(k + 1, n, A, diff, k, dp));
            }
        }
        else
        {
            if (A[j] - A[preI] == diff)
            {
                ma = max(ma, 1 + f(j + 1, n, A, diff, j, dp));
            }
            else
            {
                for (k = i + 1; k < n; k++)
                {
                    if (diff == A[k] - A[preI])
                        ma = max(ma, 1 + f(k + 1, n, A, diff, k, dp));
                }
            }
        }
    }
    return dp[i][preI + 1] = ma;
}
int lengthOfLongestAP(int A[], int n) {
    // code here

    /*Recursion+Memoization*/
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return 1 + f(0, n, A, -1, -1, dp);
}

int main()
{
    int n;
    std::cin >> n;
    int A[n];
    for (int i = 0; i < n; ++i)
        std::cin >> A[i];

    std::cout << lengthOfLongestAP(A, n);
    return 0;
}