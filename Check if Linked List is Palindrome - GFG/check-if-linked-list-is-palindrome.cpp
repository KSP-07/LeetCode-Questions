//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    
    Node *reverse(Node *head){
        Node *p = head , *q =head , *r= NULL;
        
        while(p){
            p=p->next;
            q->next = r;
            r=q;
            q=p;
        }
        return r;
    }
    bool isPalindrome(Node *head)
    {
        //Your code here
        Node *copy = new Node(head->data);
        Node *copy_head = copy;
        Node *t = head->next;
        while(t){
            Node *create= new Node(t->data);
            copy->next = create;
            copy = copy->next;
            t=t->next;
        }
        Node *modified = reverse(copy_head);
        
        Node *temp = modified , *temp2 = head;
        while(temp && temp2){
            if(temp->data != temp2->data) return 0;
            // cout<<temp2->data<<" ";
            temp=temp->next;
            temp2 =temp2->next;
        }
        return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends