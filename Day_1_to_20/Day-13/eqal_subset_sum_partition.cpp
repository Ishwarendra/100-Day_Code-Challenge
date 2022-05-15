#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

bool canPartition(vector<int> &nums)
{
    int totalSum = 0;
    for(int &num : nums)
        totalSum += num;

    if (totalSum & 1)
        return false;

    totalSum /= 2;
    vector<bool> dp(totalSum + 1, false);
    // dp[i] => if it is possible to get a subset having sum = i
    // Base-Case
    for(int &num : nums)
    {
        if (num <= totalSum)
            dp[num] = true;
    }
    dp[0] = true;

    for(int &x : nums)
    {
        for(int i = totalSum; i >= x; i--)
        {
            if (i - x >= 0)
                dp[i] = dp[i] or dp[i - x];
        }
    }

    return dp[totalSum];
}

int main()
{
    return 0;
}