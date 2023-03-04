#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s;
    int k;
    std::cin >> s >> k;

    i64 sum = 0;
    for (int i = 0; i < std::size(s); i++)
        sum += s[i] - '0';

    sum *= k;

    while (sum / 10)
    {
        i64 nsum = 0;
        while (sum)
            nsum += sum % 10, sum /= 10;

        sum = nsum;
    }

    std::cout << sum;
    
    return 0;
}