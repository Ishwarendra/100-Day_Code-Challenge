#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution 
{
public:
    int distributeCookies(std::vector<int>& cookies, int k) 
    {
        int n = std::size(cookies);

        int left = *std::max_element(std::begin(cookies), std::end(cookies)), right = 1e6;
        int ans = 0;

        auto good = [&](int mid)
        {
            std::sort(std::begin(cookies), std::end(cookies));
            int min = n;

            do 
            {
                int minGroups = 1;
                int sum = 0;

                for (int i = 0; i < n; i++)    
                {
                    if (sum + cookies[i] > mid)
                        sum = 0, minGroups++;
                    sum += cookies[i];
                }            
                
                min = std::min(min, minGroups);
            } while (std::next_permutation(std::begin(cookies), std::end(cookies)));

            return min <= k;
        };

        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (good(mid))
                ans = mid, right = mid - 1;
            else
                left = mid + 1;
        }

        return ans;
    }
};

int main()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    Solution sol;
    std::cout << sol.distributeCookies(a, k);

    return 0; 
}    