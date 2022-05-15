#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

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

ListNode *insertionSortList(ListNode *head)
{
    if (head == NULL)
        return head;

    ListNode *new_head = new ListNode(head->val); // Single element always sorted
    ListNode *itr = head;

    itr = itr->next;
    while (itr)
    {
        if (itr->val < new_head->val)
        {
            ListNode *new_node = new ListNode(itr->val, new_head);
            new_head = new_node;
        }
        else
        {
            ListNode *itr2 = new_head;
            ListNode *cur_node = new ListNode(itr->val);
            // assert(itr2->next != NULL);
            while (itr2->next and itr2->next->val < itr->val)
                itr2 = itr2->next;

            if (itr2->next)
            {
                cur_node->next = itr2->next;
                itr2->next = cur_node;
            }
            else
                itr2->next = cur_node;
        }

        itr = itr->next;
    }

    return new_head;
}

class Solution
{
public:
    ListNode *insertionSortList(ListNode *head)
    {
        if (!head)
            return head;

        ListNode *new_head = new ListNode(head->val);
        ListNode *itr = head->next;
        head->next = NULL;

        while (itr)
        {
            ListNode* itr_ka_next = itr->next;
            ListNode *itr2 = new_head;
            while (itr2->next && itr2->next->val <= itr->val)
                itr2 = itr2->next;

            itr->next = itr2->next;
            itr2->next = itr;
            itr = itr_ka_next;
        }

        return new_head;
    }
};

int main()
{
    return 0;
}