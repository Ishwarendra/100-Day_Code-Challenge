#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end());
        int ans = 1, start = points[0][0], end = points[0][1];

        for(int i = 1; i < n; i++)
        {
            if (points[i][0] <= end)
                start = max(start, points[i][0]), end = min(end, points[i][1]);
            else
                ans++, tie(start, end) =  {points[i][0], points[i][1]};
        }      

        return ans;
    }
};

int main()
{
    return 0;
}