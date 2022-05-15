#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

// https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/
class Solution
{
public:
    bool checkPowersOfThree(int n)
    {
        if (n == 2)
            return false;
        if (n == 0 || n == 1)
            return true;
        if ((n - 1)%3 == 0)
            return checkPowersOfThree((n - 1)/3);
        if (n % 3 == 0)
            return checkPowersOfThree(n/3);
        
        return false;
    }
};

int main()
{
    return 0;
}