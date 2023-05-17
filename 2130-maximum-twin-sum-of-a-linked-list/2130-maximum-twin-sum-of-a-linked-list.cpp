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
    int pairSum(ListNode* head) {
        int len = 0;
        ListNode *temp = head;
        
        while(temp){
            len++;
            temp=temp->next;
        }
        
        int k = len/2;   //for reversing the first half of the LL
        
        ListNode *p = head , *q = head , *r = NULL;
        while(k--){
            p = p->next;
            q ->next = r;
            r = q;
            q = p;
        }
        
        //now r is the new head, and p is mid crossed;
        int max_sum = 0;
        while(p){
            int sum = r->val + p->val;
            max_sum = max (max_sum , sum);
            p = p->next;
            r = r->next;
        }
        return max_sum;
    }
};