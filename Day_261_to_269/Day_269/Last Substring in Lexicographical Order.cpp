#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution 
{
public:
    std::string lastSubstring(std::string s) 
    {
        int n = std::size(s);
        int i = 0, j = 1, k = 0;
        while (j + k < n)
        {
            if (s[i + k] == s[j + k])
                k++;
            else if (s[i + k] > s[j + k])
                j += k + 1;
            else
                i = std::max(i + k + 1, j), j = i + 1;
        }

        return s.substr(i);
    }
};

int main()
{
    return 0; 
}    