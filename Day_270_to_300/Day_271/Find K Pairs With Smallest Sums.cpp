#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution 
{
    template <typename T>
    using minHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
public:
    std::vector<std::vector<int>> kSmallestPairs(std::vector<int>& nums1, 
        std::vector<int>& nums2, int k) 
    {
        int n = std::size(nums1), m = std::size(nums2);    
        std::vector<std::vector<int>> ans;

        minHeap<std::array<int, 3>> pq;
        for (int i = 0; i < n; i++)
            pq.push({nums1[i] + nums2[0], i, 0});

        while (!pq.empty() and std::size(ans) < k)
        {
            auto [sum, i, j] = pq.top();
            pq.pop();
            ans.push_back({nums1[i], nums2[j]});

            if (j + 1 < m)
                pq.push({nums1[i] + nums2[j + 1], i, j + 1});
        }

        return ans;
    }
};

int main()
{
    return 0; 
}    