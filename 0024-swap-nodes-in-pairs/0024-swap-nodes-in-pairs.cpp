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
//         ListNode *next = head;
        
//         while(next){
//             ListNode *prev = next;
//             next = next->next;
            
//             if(next){
//                 swap(prev->val , next->val);
//                 // next = prev;
//                 next = next->next;
//             }
//         }
//         return head;
        
        
        if(!head) return head;
        ListNode *dummy = new ListNode(1);
        dummy ->next = head;
        
        ListNode *curr = head;
        ListNode *prev = dummy;
        
        while(curr && curr->next){
            ListNode *temp = curr;
            // cout<<prev->next->val<<" "<<curr->next->val<<endl;
            prev->next = curr->next;  // step 1
            prev = prev->next; 
            curr->next = prev->next;   //step 2
            prev->next = temp;   //step 3
            prev = curr;  //finally placing prev at back
            curr = curr->next;   
        }
        return dummy->next;
    }
};