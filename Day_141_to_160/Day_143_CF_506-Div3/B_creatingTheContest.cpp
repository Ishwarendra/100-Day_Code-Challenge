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

    std::vector<int> a(n);

    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    std::sort(a.begin(), a.end());

    int cnt = 0;

    for (int i = 0, j = 0; i < n;)
    {
        // std::cout << i << " " << j << "\n";
        while (j < n - 1 and a[j] * 2 >= a[j + 1])
            j++;

        cnt = std::max(cnt, j - i + 1);

        i = j + 1;
        j++;
    }

    std::cout << cnt << "\n";
    
    return 0;
}