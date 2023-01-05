#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h>
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

i64 totalCost(std::vector<int>& costs, int k, int candidates) 
{
    int n = std::size(costs);
    std::multiset<std::pair<int, int>> m;
    int left = 0, right = n - 1;

    i64 ans = 0;

    int c = candidates;
    while (c and left < right) 
    {
        m.emplace(costs[left], left);
        m.emplace(costs[right], right);
        left++, right--;
        c--;
    }

    if (left == right and c)
    {
        m.emplace(costs[left], left);
        left++;
    }

    for (int i = 0; i < k; i++)
    {
        ans += std::begin(m)->first;
        int id = std::begin(m)->second;
        m.erase(std::begin(m));

        if (left <= right)
        {
            if (id <= left)
            {
                m.emplace(costs[left], left);
                left++;
            }
            else
            {
                m.emplace(costs[right], right);
                right--;
            }
        } 
    }

    return ans;
}

int main()
{
    int n, k, c;
    std::cin >> n >> k >> c;

    std::vector<int> costs(n);
    for (int i = 0; i < n; i++)
        std::cin >> costs[i];

    std::cout << totalCost(costs, k, c);
    return 0;
}