#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;

// Solution - 1 simply checking if start of interval 2 lie in prev interval
class Solution1
{
public:
    bool between(int x, int l, int u)
    {
        return (x <= u and x >= l);
    }

    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        int i = 0;
        int cur_start = intervals[0][0], cur_end = intervals[0][1];
        while (i < n)
        {
            if (between(intervals[i][0], cur_start, cur_end))
            {
                cur_end = max(cur_end, intervals[i][1]);
            }
            else
            {
                // cout << "yo ";
                ans.push_back({cur_start, cur_end});
                cur_start = intervals[i][0];
                cur_end = intervals[i][1];
            }
            // cout << cur_start << " " << cur_end << "\n";

            i++;
        }
        ans.push_back({cur_start, cur_end});
        return ans;
    }
};

// Solution-2 Here, we find union of two intervals and then return merged vector (if possible)
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        
    }
};

int main()
{
    return 0;
}