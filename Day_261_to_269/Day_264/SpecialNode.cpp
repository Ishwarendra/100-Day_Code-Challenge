#include "bits/stdc++.h"

using namespace std;

int getLeavesToRemove(int tree_nodes, std::vector<int> tree_from,
        std::vector<int> tree_to, std::vector<int> tree_weight,
        std::vector<int> arr)
{
    int n = tree_nodes;
    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 0; i < std::size(tree_to); i++)
        adj[tree_from[i] - 1].emplace_back(tree_to[i] - 1, tree_weight[i]);

    int cnt = 0;
    std::function<void(int, int, int)> dfs = [&](int u, int s, int add)
    {
        s += add;
        bool check = true;
        if (s < 0)
            s = 0, check = false;

        if (check and s > arr[u])
            return;

        cnt++;
        for (auto [v, w] : adj[u])
            dfs(v, s, w);
    }; dfs(0, 0, 0);

    return n - cnt;
}


int main()
{
    int n;
    std::cin >> n;

    std::vector<int> from(n - 1), to(n - 1), weight(n - 1), a(n);
    for (int i = 0; i < n - 1; i++)
        std::cin >> from[i];
    for (int i = 0; i < n - 1; i++)
        std::cin >> to[i];

    for (int i = 0; i < n - 1; i++)
        std::cin >> weight[i];

    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::cout << getLeavesToRemove(n, from, to, weight, a);
    return 0; 
}    