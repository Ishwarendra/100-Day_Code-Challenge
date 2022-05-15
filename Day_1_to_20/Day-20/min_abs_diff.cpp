#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> arr)
    {
        sort(arr.begin(), arr.end());

        int min_diff = INT_MAX;
        for(int i = 1; i < arr.size(); i++)
            min_diff = min(min_diff, (arr[i] - arr[i - 1]));
        
        vector<vector<int>> ans;
        for(int i = 1; i < arr.size(); i++)
        {
            if (arr[i] - arr[i - 1] == min_diff)
                ans.push_back({arr[i - 1], arr[i]});
        }
        return ans;
    }
};

int main()
{
    return 0;
}