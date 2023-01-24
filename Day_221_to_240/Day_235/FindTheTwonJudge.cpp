#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution {
public:
    int findJudge(int n, std::vector<std::vector<int>>& trust) 
    {
        std::vector<int> indeg(n);
        for (auto p : trust)    
            indeg[p[0]]++;

        int judge = 0;
        for (int i = 1; i < n; i++)
        {
            if (indeg[i] == 0)
                judge = i;
        }

        return judge;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    
    
    return 0;
}