//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

        
     cout<<isDeadEnd(root);
     cout<<endl;
    }
}


// } Driver Code Ends


/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

//iss function mai left aur right subtree ka lower bound and upper bound pass krenge , agr dono equal hogyy toh mtlb wo dead end hai , kuki uska mtlb ye hoga ki
//uss element se ek element smaller and ek element greater hai
bool solve(Node* root , int min , int max){
    if(!root) return false;
    if(min==max) return true;
    return solve(root->left, min , root->data-1) or solve(root->right ,  root->data+1 ,max);
}


/*You are required to complete below method */
bool isDeadEnd(Node *root)
{
    //Your code here
    return solve(root , 1 ,INT_MAX);
}