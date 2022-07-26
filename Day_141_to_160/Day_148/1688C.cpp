#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

void solve()
{
    int n;
    std::cin >> n;

    n *= 2;
    n += 1;

    std::vector<int> cnt(26);

    while (n--)  
    {
        std::string s;
        std::cin >> s;

        for (auto &ch : s)
            cnt[ch - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] % 2)
        {
            std::cout << char(i + 'a') << "\n"; 
            return;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while(t--)
        solve();
    
    return 0;
}