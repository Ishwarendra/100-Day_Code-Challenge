#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/top-k-frequent-elements/

// Heap-Based
class Compare
{
public:
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        return (a.second < b.second);
    }
};

vector<int>
topKFrequent(vector<int> &nums, int k)
{
    map<int, int> m;
    for (int &num : nums)
        m[num]++;

    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

    for (pair<int, int> ele_freq : m)
        pq.push(ele_freq);

    vector<int> ans;
    while (k--)
        ans.push_back(pq.top().first), pq.pop();

    return ans;
}

int main()
{
    return 0;
}