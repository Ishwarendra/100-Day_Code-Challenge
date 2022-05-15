#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

// https://leetcode.com/problems/power-of-three/
class Solution {
public:
    bool isPowerOfThree(int n) {
        unsigned long long i = 1;
        if (n <= 0)
            return false;
        while(i <= n)
        {
            if (i == n)
                return true;
            else
                i *= 3;
        }
        return false;
    }
};



int main()
{
    return 0;
}