#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

// Problem Link - https://leetcode.com/problems/linked-list-random-node/

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


// Reservoir Sampling - Algorithm R
mt19937_64 rng((int)std::chrono::steady_clock::now().time_since_epoch().count());
// int a = uniform_int_distribution<int>(2, n - 2)(rng); this is way to get one random number 
// in range n to n - 2

class Solution {
    ListNode *headNode;
public:
    Solution(ListNode* head) {
        headNode = head;        
    }
    
    int getRandom() {
        ListNode *x = headNode;
        int ans, reservoir_size = 1;
        int k = 1;
        while(x)
        {
            int j = uniform_int_distribution<int>(1, k)(rng);
            if (j <= reservoir_size)
                ans = x->val;
            k++;
            x = x -> next;
        }

        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

int main()
{
    return 0;
}