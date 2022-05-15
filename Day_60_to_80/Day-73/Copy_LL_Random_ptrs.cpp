#include<bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return NULL;
            
        // Add a dummy node after each node
        Node *itr = head;
        while(itr and itr->next)
        {
            Node *newNode = new Node(itr->val);
            Node *after = itr->next;
            
            itr->next = newNode;
            newNode->next = after;
            
            itr = itr->next->next;    
        }      
        
        // Copy Random Pointers
        itr = head;
        
        while(itr and itr->next)
        {
            itr->next->random = itr->random ? itr->random->next : itr->random;
            
            itr = itr->next->next;
        }
        
        // Break Links
        itr = head->next;
         
        Node *ans = head->next;
        
        while(head)
        { 
            head->next = itr->next;
            head = head->next;
            
            if (!head)
                break;
            
            itr->next = head->next;
            itr = itr->next;
        }
        
        return ans;
    }
};

int main()
{
    
    return 0;
}