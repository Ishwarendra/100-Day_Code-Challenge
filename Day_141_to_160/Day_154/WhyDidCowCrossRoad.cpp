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
    
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);

    std::string s;
    std::cin >> s;

    std::vector<std::pair<int, int>> pos(26, std::pair<int, int>(-1, -1));
    for (int i = 0; i < (int) s.size(); ++i)
    {
        int &F = pos[s[i] - 'A'].first;
        int &S = pos[s[i] - 'A'].second;

        (F == -1 ? F : S) = i; 
    }

    auto intersect = [&](int i, int j)
    {
        auto [S1, E1] = pos[i];
        auto [S2, E2] = pos[j];

        return (S2 <= S1 and S1 <= E2 and E1 > E2) or (S2 <= E1 and E1 <= E2 and S1 < S2);
    };

    int cnt = 0;
    for (int i = 0; i < 26; ++i)
    {
        for (int j = i + 1; j < 26; ++j)
            if (intersect(i, j))
                cnt++;
    }

    std::cout << cnt << "\n";
    
    return 0;
}