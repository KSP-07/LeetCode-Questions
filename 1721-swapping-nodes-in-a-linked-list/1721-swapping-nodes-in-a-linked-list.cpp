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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *tail = head;
        ListNode *first = head;
        ListNode *second = head;
        int cnt = 0 , m1 = 0 , m2 = 0;
        while(tail){
            cnt++;
            tail = tail->next;
        }
        
        while(m1 < k-1){
            first = first->next;
            m1++;
        }
        while(m2 != (cnt - k)){
            second = second->next;
            m2++;
        }
        
        swap(first->val , second->val);
        return head;
        
    }
};