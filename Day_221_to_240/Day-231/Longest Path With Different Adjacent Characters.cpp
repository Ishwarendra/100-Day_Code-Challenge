#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution {
public:
    int longestPath(std::vector<int>& parent, std::string s)
    {
        int n = std::size(parent);
        std::vector<int> adj[n];

        for (int i = 1; i < n; i++)
            adj[parent[i]].emplace_back(i);

        std::vector<int> ans(n);
        int len = 0;
        std::function<void(int)> dfs;
        dfs = [&](int u)
        {
            int max = 0, sec_max = 0;
            for (int v : adj[u])
            {
                dfs(v);

                if (s[u] != s[v])
                {
                    if (ans[v] > max)
                        sec_max = max, max = ans[v];
                    else if (ans[v] > sec_max)
                        sec_max = ans[v];
                }
            }

            ans[u] = max + 1;
            len = std::max(len, max + sec_max + 1);
        };
        dfs(0);

        return len;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::string s;

    std::cin >> n;

    std::vector<int> parent(n);
    for (int i = 0; i < n; i++)
        std::cin >> parent[i];

    std::cin >> s;

    Solution sol;
    std::cout << sol.longestPath(parent, s);

    return 0;
}