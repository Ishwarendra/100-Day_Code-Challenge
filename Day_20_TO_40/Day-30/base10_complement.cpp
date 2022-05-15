#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

class Solution {
public:
    void setBit(int &n, int pos)
    {
        n = (n | (1 << pos));
    }
        
    int getBit(int n, int pos)
    {
        return (n & (1 << pos));
    }
    
    int bitwiseComplement(int n) {
        if (n == 0)
                return 1;
        
        int i = 0;
        int ans = 0;
        while(n != 0)
        {
            int bit = getBit(n, 0);
            n >>= 1;
            if (bit == 0)
                setBit(ans, i);
            i++;
        }
        return ans;
    }
};

int main()
{
    return 0;
}