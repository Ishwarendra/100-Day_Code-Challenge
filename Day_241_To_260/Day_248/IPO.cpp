#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution {
public:
    int findMaximizedCapital(int k, int w, std::vector<int>& profits, std::vector<int>& capital) 
    {
        std::multiset<int, std::greater<int>> can_do;
        int n = std::size(profits);
        std::vector<std::pair<int, int>> a(n);

        for (int i = 0; i < n; i++)
            a[i] = {capital[i], profits[i]};

        std::sort(std::begin(a), std::end(a));
        int pos = 0;
        for (auto [c, p] : a)
        {
            if (c <= w)
            {
                pos++;
                can_do.emplace(p);
            }
        }

        while (k-- and !can_do.empty())
        {
            auto cur = *std::begin(can_do);
            can_do.erase(std::begin(can_do));
            w += cur;

            for (; pos < n and a[pos].first <= w; pos++)
                can_do.emplace(a[pos].second);
        }

        return w;
    }   
};

int main()
{
    return 0; 
}    