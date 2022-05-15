#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

/*
If we fix root node as `i` then possible bst
f(i) = summmation over i (f(n - i) * f(i - 1))
                              |          |
                          rightsubtree  left subtree
summation formula = 2n C n / (n + 1)
or you can use dp
*/

class Solution1
{
    // vector<int> dp;
    int C(int n, int r)
    {
        if (r == 0)
            return 1;
        return (n * C(n - 1, r - 1)) / (r);
    }

public:
    int numTrees(int n)
    {
        // dp.resize(n + 1);
        // dp[0] = 0, dp[1] = 1;
        // for(int i = 0; i < n; i++)
        return C(2 * n, n) / (n + 1);
    }
};

class Solution
{
    vector<int> dp;
public:
    void preprocess(int n)
    {
        dp.resize(n + 1);
        dp[0] = 1;

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= i; j++)
                dp[i] += (dp[j - 1] * dp[i - j]);
        }
    }

    int numTrees(int n)
    {
        preprocess(n);
        return dp[n];
    }
};

int main()
{
    return 0;
}