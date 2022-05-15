#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

// Move a[i] to end if it's zero;

class Solution {
public:
    void moveZeroes(vector<int>& a) {
        int zeroCount = 0;
        int n = a.size();
        for(int i = 0; i < n; i++)
        {
            if (a[i] != 0)
                a[zeroCount++] = a[i];
        }

        for(int i = zeroCount; i < n; i++)
            a[i] = 0;
    }
};

int main()
{
    return 0;
}