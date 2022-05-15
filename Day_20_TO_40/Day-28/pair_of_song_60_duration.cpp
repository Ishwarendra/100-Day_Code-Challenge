// Problem Link - https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60

#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

class Solution
{
public:
    int numPairsDivisibleBy60(vector<int> &time)
    {
        int n = time.size(), cnt = 0;
        vector<int> rem(n);

        for (int i = 0; i < n; i++)
            rem[i] = (time[i] % 60);

        unordered_map<int, int> m;
        m[rem[0]]++;
        for (int i = 1; i < n; i++)
        {
            if (m.find((60 - rem[i]) % 60) != m.end())
                cnt += m[(60 - rem[i]) % 60];

            m[rem[i]]++;
        }

        return cnt;
    }
};

int main()
{
    return 0;
}