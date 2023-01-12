//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



float findMedian(struct Node* node);

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));
 
   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}

int main() {
  
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   //cout << t << endl;
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root = buildTree(s);

      // getline(cin, s);
       
        cout << findMedian(root) << endl;

      // cout<<"~"<<endl;
   }
   return 0;
}
// } Driver Code Ends


/*
Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

//USING MORRIS TRAVERSAL

// int length(Node* root){
//     if(!root) return 0;
//     int left = length(root->left);
//     int right =length(root->right);
//     return 1 +left+right;
// }

  //morris inorder traversal
  
 //morris traversal se length find kr rhe 
 void morrisTraversal(Node * root,int &count)
{
    if(root==NULL)
    return;
    Node * curr=root;
    while(curr)
    {
        if(curr->left==NULL)
        {
            count++;
            curr=curr->right;
        }
        else
        {
            Node * prev=curr->left;
            while(prev->right!=NULL && prev->right!=curr)
            prev=prev->right;
            if(prev->right==NULL)
            {
                prev->right=curr;
                curr=curr->left;
            }
            else
            {
                prev->right=NULL;
                count++;
                curr=curr->right;
            }
            
        }
    }
}

//morris traversal se kth element find kr rhee
void getMorrisTraversal(Node * root,int &count,float & temp)
{
    if(root==NULL)
    return;
    Node * curr=root;
    while(curr)
    {
        if(curr->left==NULL)
        {
            count--;
            if(count==0)
            {
                temp=curr->data;
                // return;
            }
            curr=curr->right;
        }
        else
        {
            Node * prev=curr->left;
            while(prev->right!=NULL && prev->right!=curr)
            prev=prev->right;
            if(prev->right==NULL)
            {
                prev->right=curr;
                curr=curr->left;
            }
            else
            {
                prev->right=NULL;
                count--;
                if(count==0)
                {
                    temp=curr->data;
                    // return;
                }
                curr=curr->right;
            }
            
        }
    }
}
float findMedian(struct Node *root)
{
      //Code here
      int count=0;
      morrisTraversal(root,count);
      float temp1;
      int temp1count=count/2+1;
      getMorrisTraversal(root,temp1count,temp1);
      if(count%2)
      return temp1;
      float temp2;
      int temp2count=count/2;
      getMorrisTraversal(root,temp2count,temp2);
      return (temp1+temp2)/2;
}