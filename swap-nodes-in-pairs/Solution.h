// 24. Swap Nodes in Pairs
// Medium


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        if (!head) {
            return head; 
        }
        
        ListNode* newHead = _swapPairs(head);         

        return newHead; 
        
    }
    
private: 
    
    ListNode* _swapPairs(ListNode* first) {
        
        if (!first || !first->next) {
            // base case
            return first;
        }
            
        ListNode* second = first->next;
        
        first->next = _swapPairs(second->next);
        second->next = first;
            
        return second; 
    }
    
};