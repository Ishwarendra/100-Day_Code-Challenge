#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

// https://leetcode.com/problems/find-the-town-judge/
class Solution
{
    vector<set<int>> adj1, adj2;

public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        adj1.resize(n + 1, set<int>()); // a -> trust these people
        adj2.resize(n + 1, set<int>()); // a -> people who trust a

        for (int i = 0; i < trust.size(); i++)
        {
            adj1[trust[i][0]].insert(trust[i][1]);
            adj2[trust[i][1]].insert(trust[i][0]);
        }

        int tj_candi = 0;
        int ans = -1;
        for (int i = 1; i <= n; i++)
        {
            // Town judge trust 0 people and is trusted by n - 1 people not himself ofc
            if (adj1[i].size() == 0 and adj2[i].size() == n - 1 and adj2[i].find(i) == adj2[i].end())
                ans = i, tj_candi++;
        }

        return (tj_candi == 1 ? ans : -1);
    }
};

int main()
{

    return 0;
}