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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int,int> st;
        
        ListNode* tHead = head;
        ListNode* prev = new ListNode(0);
        ListNode* mark=prev;
        
        while(tHead){
            st[tHead->val]++;
            tHead= tHead->next;
        }
        
        for(auto i: st){
            
            if(i.second<2){
                // cout<<i.first<<" "<<i.second<<" ";
                ListNode* curr=new ListNode(i.first);
                prev->next = curr;
                prev=prev->next;
            }
        }
        return mark->next;
    }
};