#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::vector<int> cnt(26);

    for (int i = 0; i < 26; ++i)
        for (int j = i + 1; j < 26; ++j)
        {
            // char i lie after j
            int lastI = -1, firstJ = n;
            for (int k = 0; k < n; ++k)
            {
                if (s[k] - 'a' == i)
                    lastI = std::max(lastI, k);
                else if (s[k] - 'a' == j)
                    firstJ = std::min(firstJ, k);
            }

            if (lastI != -1 and firstJ != n and lastI > firstJ)
            {
                std::cout << "YES\n";
                std::cout << firstJ + 1 << " " << lastI + 1 << "\n";
                return 0;
            }
        }   

        std::cout << "NO\n";
        
    return 0;
}