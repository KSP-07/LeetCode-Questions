//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one

        Node *prev = NULL , *curr=head;
        bool flag = false;
        while(curr){
            if(curr->next == NULL){
                if(curr->data<9){
                    curr->data = curr->data+1;
                }
                else flag =true;
            }
            else{
                if(curr->data < 9){
                    prev= curr;
                }
            }
            curr = curr->next;
        }
        if(!flag) return head;
        
        else{
            if(prev==NULL){  //means all numbers are 9's
                Node *temp = new Node(0);
                temp->next =head;
                head = temp;
                prev = head;
            }
            prev->data = prev->data +1;
            prev=prev->next;
            while(prev){
                prev->data =0;
                prev= prev->next;
            }
        }
        return head;
        
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends