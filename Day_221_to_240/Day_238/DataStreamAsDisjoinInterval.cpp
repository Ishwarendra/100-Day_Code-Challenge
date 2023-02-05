#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

class SummaryRanges 
{
    std::set<int> nums;
public:
    SummaryRanges()  {}
    
    void addNum(int value) 
    {
        nums.emplace(value);
    }
    
    std::vector<std::vector<int>> getIntervals() 
    {
        std::vector<std::vector<int>> ans;

        if (nums.empty())
        {
            ans.emplace_back();
            return ans;
        }

        auto it = std::begin(nums);
        int left = *it, right = *it;
        it++;

        for (; it != std::end(nums); it++)
        {
            if (*it == right + 1)
                right++;
            else
            {
                ans.push_back({left, right});
                left = right = *it;          
            }
        }

        ans.push_back({left, right});

        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */

void f(int = 1);

void f (int x)
{
    std::cout << x << std::endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    f();
    
    return 0;
}