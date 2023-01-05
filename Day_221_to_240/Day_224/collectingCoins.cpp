#include "bits/stdc++.h"

std::vector<long long> solve(int n, int m, std::vector<int> a, std::vector<int> b, std::vector<int> c)
{
    std::vector<std::pair<int, int>> monster(m);
    std::vector<long long> cost(m);
    for (int i = 0; i < n; i++)
        monster[i] = {b[i], c[i]};

    std::sort(monster.begin(), monster.end(), [&](std::pair<int, int> &a, std::pair<int, int> &b)
        {
            if (a.first == b.first)
                return a.second > b.second;
            
            return a.first < b.first;
        });

    cost[0] = monster[0].second;
    for (int i = 1; i < m; i++) 
        cost[i] = cost[i - 1] + monster[i].second;

    std::vector<long long> ans(n);
    for (int i = 0; i < n; i++)
    {
        std::pair<int, int> health {a[i], int(1e9)};
        auto it = std::upper_bound(monster.begin(), monster.end(), health) - monster.begin();

        if (it == 0)
            ans[i] = 0;
        else
            ans[i] = cost[--it];
    }

    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n), b(m), c(m);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    for (int i = 0; i < m; i++)
        std::cin >> b[i];
    for (int i = 0; i < m; i++)
        std::cin >> c[i];

    auto ans = solve(n, m, a, b, c);
    for (int i = 0; i < ans.size(); i++)
        std::cout << ans[i] << " ";
    std::cout << "\n";
    
    return 0;
}