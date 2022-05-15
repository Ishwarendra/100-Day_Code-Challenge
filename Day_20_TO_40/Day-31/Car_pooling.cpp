#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

class Solution {
    int getLength(vector<vector<int>> &trips)
    {
        int len = 1;
        for(vector<int> &trip : trips)
        {
            len = max(len, trip[2]);
        }

        return len + 1;
    }  
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> arr(getLength(trips) + 2);

        for(int i = 0; i < trips.size(); i++)
        {
            int people = trips[i][0];
            int start = trips[i][1], end = trips[i][2];
            arr[start] += people;
            arr[end] -= people;
        }
            
        if(arr[0] > capacity)
            return false;
        
        for(int i = 1; i < arr.size(); i++)
        {
            arr[i] += arr[i - 1];
            if (arr[i] > capacity)
                return false;
        }
        for(int i : arr)
                cout << i << " ";
        return true;
    }
};

int main()
{
    return 0;
}