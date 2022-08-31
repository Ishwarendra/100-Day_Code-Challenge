#include <bits/stdc++.h>
using namespace std;

#define LOCAL 1

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

long findMaximumProfit(vector<int> category, vector<int> price)
{
    int n = category.size();
    long ans = 0;
    vector<pair<int, int>> a(n);

    int sz = *std::max_element(std::begin(category), std::end(category));
    std::vector<int> adj[sz];

    for (int i = 0; i < n; i++)
        adj[category[i]].emplace_back(price[i]);

    for (int i = 0; i < sz; ++i)
        std::sort(adj[i].begin(), adj[i].end());
    

    return ans;
}   

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> c(n), p(n);
    for (int i = 0; i < n; ++i)
        std::cin >> c[i];
    for (int i = 0; i < n; ++i)
        std::cin >> p[i];

    std::cout << findMaximumProfit(c, p);
    return 0; 
}    