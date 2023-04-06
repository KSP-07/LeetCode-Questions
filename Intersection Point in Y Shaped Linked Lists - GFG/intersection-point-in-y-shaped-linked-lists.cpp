//{ Driver Code Starts
#include<iostream>

#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}


// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    // unordered_map<Node* , int> mp;
    Node *temp = head1 , *temp2 = head2;
    
    int cnt1 = 0 , cnt2=0;
    while(temp){
        cnt1++;
        temp = temp->next;
    }
    temp = head2;
    while(temp){
        cnt2++;
        temp = temp->next;
    }
    
    int diff ;
    Node *ptr1 , *ptr2;
    if(cnt1 > cnt2){
        diff = cnt1-cnt2;
        ptr1 = head1;
        ptr2= head2;
    }
    else{
        diff = cnt2-cnt1;
        ptr1=head2;
        ptr2 = head1;
    }
    
    while(diff){
        diff--;
        ptr1= ptr1->next;
    }
    
    while(ptr1 && ptr2){
        if(ptr1==ptr2) return ptr1->data;
        ptr1= ptr1->next;
        ptr2= ptr2->next;
    }
    
    return -1;
}

