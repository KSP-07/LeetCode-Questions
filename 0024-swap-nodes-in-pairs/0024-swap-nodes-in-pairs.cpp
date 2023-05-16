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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *next = head;
        
        while(next){
            ListNode *prev = next;
            next = next->next;
            
            if(next){
                swap(prev->val , next->val);
                // next = prev;
                next = next->next;
            }
        }
        return head;
    }
};