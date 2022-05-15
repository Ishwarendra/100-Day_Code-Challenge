#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    vector<int> ans;
    for(ListNode* cur : lists)
    {
        ans.push_back(cur->val);
        while(cur->next)
        {
            cur = cur->next;
            ans.push_back(cur->val);
        }
    }

    sort(ans.begin(), ans.end());

    if (ans.size() == 0)
        return NULL;

    ListNode *start = new ListNode(ans[0]);
    ListNode *temp = start;

    for(int i = 1; i < ans.size(); i++)
    {
        temp->next = new ListNode(ans[i]);
        temp = temp->next;
    }

    return start;
}

int main()
{
    return 0;
}