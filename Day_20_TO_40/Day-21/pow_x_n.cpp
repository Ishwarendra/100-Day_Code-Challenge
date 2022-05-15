#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double myPowHelper(double x, int n)
    {
        if (n == 0)
            return 1;

        double ans = myPowHelper(x, n/2);
        if (n % 2 == 0)
            return ans * ans;
        else
            return x * ans * ans;
    }   

    double myPow(double x, int n)
    {
        if (n < 0)
            return 1/(myPowHelper(x, -n));
        
        return myPowHelper(x, n);
    }
};

int main()
{
    return 0;
}