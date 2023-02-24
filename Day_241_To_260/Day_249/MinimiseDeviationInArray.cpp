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
    int minimumDeviation(std::vector<int>& nums) 
    {
        int n = std::size(nums);
        std::multiset<int, std::greater<int>> m;

        for (int i = 0; i < n; i++)
            m.emplace(nums[i] * (nums[i] % 2 ? 2 : 1));

        int ans = *(std::begin(m)) - *(--std::end(m));

        while ((*std::begin(m)) % 2 == 0)
        {
            int max = *std::begin(m);
            m.erase(std::begin(m));
            m.emplace(max / 2);

            ans = std::min(ans, *(std::begin(m)) - *(--std::end(m)));
        }

        return ans;
    }
};

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    Solution sol;
    std::cout << sol.minimumDeviation(a);
    return 0; 
}    