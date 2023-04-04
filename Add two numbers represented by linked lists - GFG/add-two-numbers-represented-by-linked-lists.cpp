//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    
    //dono link list ko reverse krke sum krke ans waps reverse krke dedia
    public:
    Node *reverse(Node *head){
        Node *p =head , *q = head , *r = NULL;
        while(p){
            p = p->next;
            q->next = r;
            r = q;
            q=p;
        }
        return r;
    }
    Node *add(Node *first , Node *second){
        int carry =0;
        Node *ans = new Node(0);
        Node *temp = ans;
        
        while(first && second){
            int sum = carry + first->data + second->data;
            int digit = sum%10;
            carry= sum/10;
            
            Node *temp_node = new Node(digit);
            // cout<<temp_node->data<<" ";
            temp->next = temp_node;
            temp = temp->next;
            
            first = first->next;
            second = second->next;
        }
        
        while(first){
            int sum = carry + first->data;
            int digit = sum%10;
            carry = sum/10;
            
            Node *temp_node = new Node(digit);
            temp->next = temp_node;
            temp = temp->next;
            first = first->next;
        }
        while(second){
            int sum = carry + second->data;
            int digit = sum%10;
            carry = sum/10;
            
            Node *temp_node = new Node(digit);
            temp->next = temp_node;
            temp = temp->next;
            second = second->next;
        }
        while(carry){
            int sum = carry;
            int digit = sum%10;
            carry = sum/10;
            
            Node *temp_node = new Node(digit);
            temp->next = temp_node;
            temp = temp->next;

        }
        if(ans->next) ans = reverse(ans->next);   //agar sirf ek element ki list aai toh uska edge case ke liye
        return ans;
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        
        first = reverse(first);
        second = reverse(second);
        
        return add(first , second);
        
   }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends