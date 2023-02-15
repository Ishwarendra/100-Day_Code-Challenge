#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution 
{
public:
    int countOdds(int low, int high) 
    {
        int n = (high - low + 1);
        
        if (n % 2)
            return n / 2 + (low % 2);

        return n / 2;
    }
};

int main()
{
    return 0; 
}    