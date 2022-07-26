#include<bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);

    int n;
    std::cin >> n;

    std::vector<int> tot_cnt(26);

    for (int i = 0; i < n; i++)
    {
        std::string s, t;
        std::cin >> s >> t;

        std::vector<int> cnt1(26), cnt2(26);
        for (char ch : s)
            cnt1[ch - 'a']++;
        for (char ch : t)        
            cnt2[ch - 'a']++;

        for (int i = 0; i < 26; i++)
            tot_cnt[i] += std::max(cnt1[i], cnt2[i]);
    }

    for (int i = 0; i < 26; ++i)
        std::cout << tot_cnt[i] << "\n";
        
    return 0;
}