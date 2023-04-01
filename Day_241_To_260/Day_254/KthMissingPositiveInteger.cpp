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
    int findKthPositive(std::vector<int>& arr, int k) 
    {
        int ans = 1;
        int pos = 0;

        while (k > 0)    
        {
            if (pos < std::size(arr) and arr[pos] == ans)
                ans++, pos++;
            else
                ans++, k--;
        }

        return --ans;
    }
};

int main()
{
    return 0; 
}    