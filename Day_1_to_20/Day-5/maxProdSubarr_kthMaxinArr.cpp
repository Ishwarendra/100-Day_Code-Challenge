#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-product-subarray/
// two loops
int maxProduct_TwoPass(vector<int> &nums)
{
    int n = nums.size(), max_prod = INT_MIN, cur_prod = 1;

    for (int i = 0; i < n; i++)
    {
        cur_prod *= nums[i];
        max_prod = max(max_prod, cur_prod);
        if (cur_prod == 0)
            cur_prod = 1;
    }

    cur_prod = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        cur_prod *= nums[i];
        max_prod = max(max_prod, cur_prod);
        if (cur_prod == 0)
            cur_prod = 1;
    }

    return max_prod;
}

// in one single loop
int maxProduct(vector<int> &nums)
{
    int n = nums.size();
    int max_prod = INT_MIN, start = 0, end = n - 1;
    int start_prod = 1, end_prod = 1;

    for (int i = 0; i < n; i++)
    {
        start_prod *= nums[start++];
        end_prod *= nums[end--];

        max_prod = max({max_prod, start_prod, end_prod});

        if (start_prod == 0)
            start_prod = 1;
        if (end_prod == 0)
            end_prod = 1;
    }

    return max_prod;
}

// https://leetcode.com/problems/kth-largest-element-in-an-array/
int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i : nums)
        pq.push(nums);
    k--;
    while(k--)
        pq.pop();
        
    return pq.top();
} 

int main()
{
    return 0;
}