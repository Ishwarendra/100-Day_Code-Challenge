#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution {
public:
    std::vector<int> countSubTrees(int n, std::vector<std::vector<int>>& edges, 
        std::string labels) 
    {
        std::vector<int> adj[n];
        for (auto edge : edges)
        {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }

        std::vector<int> res(n);

        std::function<std::vector<int>(int, int)> dfs = [&](int u, int p)
        {
            std::vector<int> ans(26);
            ans[labels[u] - 'a']++;
            for (auto v : adj[u])
            {
                if (v == p)
                    continue;

                auto child_ans = dfs(v, u);
                for (int i = 0; i < 26; i++)
                    ans[i] += child_ans[i];
            }

            res[u] = ans[labels[u] - 'a'];
            return ans;
        };

        dfs(0, 0);
        return res;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    
    
    return 0;
}