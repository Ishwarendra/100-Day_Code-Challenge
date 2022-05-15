#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

class Solution {
    void rotate(vector<int> &nums, int start, int end)
    {
        int i = start, j = end;
        while(i < j)
        {
            swap(nums[i], nums[j]);
            i++, j--;
        }
    }

public:
    void rotate(vector<int>& nums, int k) {
        rotate(nums, 0, nums.size() - 1);
        rotate(nums, 0, k - 1);
        rotate(nums, k, nums.size() - 1);
    }
};

int main()
{
    return 0;
}