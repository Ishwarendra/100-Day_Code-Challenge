#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
      bool canPlaceFlowers(vector<int> &flowerbed, int k)
      {
            int i = 0, valid_pos = 0, n = flowerbed.size();
            while(i < n)
            {
                  if (flowerbed[i] == 0 and (i == 0 or flowerbed[i - 1] == 0) and (i == n - 1 or flowerbed[i + 1] == 0))
                        valid_pos++, flowerbed[i] = 1;
            }
            return valid_pos >= k;
      }
};