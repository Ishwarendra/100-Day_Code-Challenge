#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

class Solution
{
public:
     int minMoves(vector<int> &nums, int k)
     {
          vector<int> pos;
          for(int i = 0; i < nums.size(); i++)
          {
               if (nums[i] == 1)
                    pos.push_back(i); // stores indices of 1
          }

          int n = pos.size();

          // Prefix sum
          map<int, int> m; // stores prefix sum upto index i
          for(int i = 0; i < n; i++)
               m[i] = m[i - 1] + pos[i];

          int ans = 1e9;
          for(int i = 0; i < n - k + 1; i++)
          {
               int mid = (2*i + k)/2;
               int left = m[mid - 1] - m[i - 1];
               int right = m[i + k - 1] - m[mid];

          }
          int r = (k - 1)/2;
          ans -= r*(r + 1) + (k % 2 == 0 ? r + 1 : 0);
          ans = min(ans, right - left + (k % 2 == 0 ? pos[mid] : 0));

          return ans;
     }
};