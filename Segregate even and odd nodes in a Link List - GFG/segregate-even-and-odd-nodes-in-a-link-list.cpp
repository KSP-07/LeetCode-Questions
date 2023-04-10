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
        cout << node->data <<" "; 
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
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        Node *odd = new Node(0);
        Node *even = new Node(0);
        Node *p = odd , *q = even;
        
        Node *temp = head;
        
        while(temp){
            if(temp->data %2 == 0){
                Node *newNode = new Node(temp->data);
                q->next = newNode;
                q = q->next;
            }
            else{
                Node *newNode = new Node(temp->data);
                p->next = newNode;
                p = p->next;
            }
            temp = temp->next;
        }
        if(!odd->next || !even->next) return head;
        if(q && odd->next){
            q->next = odd->next;   
        }
        return even->next;
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends