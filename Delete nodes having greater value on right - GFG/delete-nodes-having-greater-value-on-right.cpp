//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *reverse(Node *head){
        Node *p =head , *q = head , *r = NULL;
        
        while(p){
            p = p->next;
            q->next = r;
            r=q;
            q=p;
        }
        return r;
    }
    
    //reverese krke nikal lenge kaun chota hai and then dels krne ke baaad waps reverse
    Node *compute(Node *head)
    {
        // your code goes here
        Node *rev = reverse(head);
        
        int curr_max= rev->data;
        
        Node *temp = rev , *prev =NULL;
        while(temp){
            if(temp->data < curr_max){
                Node *del = temp;
                temp = temp->next;
                prev->next =temp;
                delete del;
                continue;
            }
            curr_max = max(curr_max , temp->data);
            prev = temp;
            
            temp = temp->next;
        }
        return reverse(rev);
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends