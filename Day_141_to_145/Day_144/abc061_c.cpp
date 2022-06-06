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
    
    long long n, k;
    std::cin >> n >> k;

    std::vector<int> a(n), b(n);

    for (int i = 0; i < n; ++i)
        std::cin >> a[i] >> b[i];

    std::map<int, long long> m;

    for (int i = 0; i < n; ++i)
        m[a[i]] += b[i];

    for (auto &p : m)
    {
        if (p.second < k)
            k -= p.second;
        else
        {
            std::cout << p.first << "\n";
            return 0;
        }
    }
    
    return 0;
}