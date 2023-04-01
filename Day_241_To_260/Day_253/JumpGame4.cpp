#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution 
{
    const int inf = 1e9;
public:
    int minJumps(std::vector<int>& arr) 
    {
        int n = std::size(arr);
        std::map<int, std::vector<int>> pos;

        for (int i = 0; i < n; i++)
            pos[arr[i]].emplace_back(i);

        std::vector<int> d(n, inf);
        d[0] = 0;

        std::queue<int> q;
        q.emplace(0);

        while (!q.empty())
        {
            auto u = q.front();
            q.pop();

            if (u - 1 >= 0 and d[u - 1] == inf)
            {
                d[u - 1] = d[u] + 1;
                q.emplace(u - 1);
            }
            if (u + 1 < n and d[u + 1] == inf)
            {
                d[u + 1] = d[u] + 1;
                q.emplace(u + 1);
            }

            for (auto p : pos[arr[u]])
            {
                if (d[p] == inf)
                {
                    d[p] = d[u] + 1;
                    q.emplace(p);
                }
            }

            pos.erase(arr[u]);
        }

        return d.back();
    }
};

int main()
{
    return 0; 
}    