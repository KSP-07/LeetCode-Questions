/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //MAP BRUTE APPROACH
    // ListNode *detectCycle(ListNode *head) {
    //     ListNode *temp = head;
    //     unordered_map <ListNode*,int> mp;
    //     while(temp){
    //         if(mp.find(temp) !=mp.end()) return temp;
    //         mp[temp]++;
    //         temp = temp->next;
    //     }
    //     return NULL;
    // }
    
    
    //floyd warshall tortoise and hare
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return NULL;
        
        ListNode *slow =head;
        ListNode *fast = head;
        ListNode *entry = head;
        
        while(fast->next  && fast->next->next){     //if fast reaches NULL , there eas never a cycle
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow==fast){     //there is a cycle
                while(slow!=entry){
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        return NULL;
    }
};