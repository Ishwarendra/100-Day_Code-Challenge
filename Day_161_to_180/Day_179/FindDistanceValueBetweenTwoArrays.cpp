#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

class Solution 
{
public:
    int findTheDistanceValue(std::vector<int>& arr1, std::vector<int>& arr2, int d) 
    {
        int n = std::size(arr1), m = std::size(arr2);
        int ans = 0;

        std::sort(std::begin(arr2), std::end(arr2));
        for (int i = 0; i < n; ++i)           
        {
            bool dont_add = false;

            auto left = std::lower_bound(std::begin(arr2), std::end(arr2), arr1[i] - d) - std::begin(arr2);
            auto right = std::upper_bound(std::begin(arr2), std::end(arr2), arr1[i] + d) - std::begin(arr2);
            right--;

            if (left < m)
                dont_add =  abs(arr2[left] - arr1[i]) <= d;
            if (right >= 0)
                dont_add = abs(arr2[right] - arr1[i]) <= d;

            ans += !dont_add;
        }

        return ans;
    }   
};

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    int m;
    std::cin >> m;

    std::vector<int> b(m);
    for (int i = 0; i < m; ++i)
        std::cin >> b[i];

    int d;
    std::cin >> d;

    Solution sol;
    std::cout << sol.findTheDistanceValue(a, b, d);
    return 0; 
}    