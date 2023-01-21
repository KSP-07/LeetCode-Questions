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



// } Driver Code Ends
/*
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
// class Solution
// {
//     public:
    
//     void in1(Node *root, vector<int> &a)
//     {
//         if(!root) return;
//         in1(root->left,a);
//         a.push_back(root->data);
//         in1(root->right,a);
//     }
//     void in2(Node *root, vector<int> &b)
//     {
//         if(!root) return;
//         in2(root->left,b);
//         b.push_back(root->data);
//         in2(root->right,b);
        
//     }
    
//     vector<int> merge(Node *root1, Node *root2)
//     {
//         vector<int> a,b;
//         in1(root1,a);
//         in2(root2,b);
        
//         int s1 = a.size()-1 , s2 = b.size()-1;        
//         vector<int> s;
//         int i=0,j=0;
//         while(i<=s1  && j<=s2)
//         {
//             if(a[i]<b[j])
//             {
//                 s.push_back(a[i++]);
                
//             }
//             else
//             {
//                 s.push_back(b[j++]);
//             }
//         }
//         while(i<=s1)
//         {
//             s.push_back(a[i++]);
//         }
//         while(j<=s2)
//         {
//             s.push_back(b[j++]);
//         }
//         return s;
        
//     }
    
// };


//optimal
class Solution
{
    public:
    
    void inorder(Node *root, vector<int> &ans){
        if(!root) return;
        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right , ans);
    }
    
    vector<int> merge(Node *root1, Node *root2){
        if(!root1 && !root2) return {-1};
        vector<int> ans;
        if(root1==NULL){   //if first tree is not there then ans will be second tree
            inorder(root2 , ans);
            return ans;
        }
        if(root2==NULL){
            inorder(root1 , ans);
            return ans;
        }
        
        Node *c1=root1;
        Node *c2=root2;
        
        stack<Node *> s1;
        stack<Node *> s2;
        
        while(c1!=NULL || !s1.empty() || c2!=NULL || !s2.empty()){
            //if any of the two pointers in not empty
            if(c1!=NULL || c2!=NULL){
                //reaching leftmost node of bst and pushing ancestors of nodes to stack
                if(c1!=NULL){
                    s1.push(c1);
                    c1=c1->left;
                }
                if(c2!=NULL){
                    s2.push(c2);
                    c2=c2->left;
                }
            }//else both pointers point to null then
            else{
                //if either tree is exhausted then we will have ans in the second tree
                if(s1.empty()){
                    while(!s2.empty()){
                        c2=s2.top();
                        s2.pop();
                        c2->left=NULL;     //since c2 was pointing to null , to ab wo root pe aagya stack se lene ke baad, to uss root ke left NULL set kr rhe , kuki wo store ho chuka
                        //aur agar nhi krenge to leftmost calculate krne mai element firse calculate hojayga
                        inorder(c2,ans);   //will store inorder of subtrees to get final inorder of tree
                    }
                    return ans;
                }
                if(s2.empty()){
                    while(!s1.empty()){
                        c1=s1.top();
                        s1.pop();
                        c1->left=NULL;
                        inorder(c1, ans);
                    }
                    return ans;
                }
                //if no tree has exhausted then
                //we pop first element from both stacks to compare them
                c1=s1.top();
                c2=s2.top();
                s1.pop();
                s2.pop();
                
                //if element of first tree is smaller , we store it in vec and move pointer to its right
                //we push the other element back into the stack for further evaluation
                if(c1->data < c2->data){
                    ans.push_back(c1->data);
                    c1=c1->right;
                    s2.push(c2);
                    c2=NULL;   //as it was null that's why it came to evaluation, keeping it as it was
                }
                else{
                    ans.push_back(c2->data);
                    c2=c2->right;
                    s1.push(c1);
                    c1=NULL;
                }
            }
        }
        return ans;
    }
    
    
    
    
    //Babbar's solution
    // //tree ko doubly linked list mai convert kr rhee
    // void convertIntoSortedDLL(Node *root , Node *&head){
    //     //base
    //     if(root==NULL) return ;
        
    //     convertIntoSortedDLL(root->right , head);  //root ke right pe call krdia
        
    //     //ab recursion right se ans laa dega toh fir root ke right mai usse laga denge
    //     root->right=head;
        
    //     //agar ans jo aaya wo null hai, to uska kuch left to hoga nhi
    //     if(head!=NULL) {
    //         head->left=root;
    //     }
        
    //     head=root; //head ko ab root pe point krderhe hai kuki ab left side pe ans nikalenge to uske liye
    //     //curr right side hogi
        
    //     convertIntoSortedDLL(root->left, head);
    // }
    
    // Node* mergeLinkedList(Node *head1 , Node *head2){
    //     Node *head=NULL;
    //     Node *tail=NULL;
        
    //     while(head1!=NULL && head2!=NULL){
    //         if(head1->data < head2->data){
    //             if(head==NULL){
    //                 head=head1;
    //                 tail=head1;
    //                 head1=head1->right;
    //             }
    //             else{
    //                 tail->right=head1;
    //                 head1->left=tail;
    //                 tail= head1;
    //                 head1= head1->right;
    //             }
    //         }
    //         else{
    //             if(head==NULL){
    //                 head=head2;
    //                 tail=head2;
    //                 head2=head2->right;
    //             }
    //             else{
    //                 tail->right=head2;
    //                 head1->left=tail;
    //                 tail= head2;
    //                 head2= head2->right;
    //             }
    //         }
    //     }
        
    //     while(head1 != NULL){
    //         tail->right=head1;
    //         head1->left=tail;
    //         tail= head1;
    //         head1= head1->right;
    //     }
    //     while(head2!=NULL){
    //         tail->right=head2;
    //         head1->left=tail;
    //         tail= head2;
    //         head2= head2->right;
    //     }
    //     return head;
    // }
    
    // int countNodes(Node * head){
    //     int cnt=0;
    //     Node* temp=head;
    //     while(temp!=NULL){
    //         cnt++;
    //         temp= temp->right;
    //     }
    //     return cnt;
    // }
    
    // Node *sortedLLtoBST(Node *&head, int n){
    //     //basecase
    //     if(n<=0 || head==NULL){
    //         return NULL;
    //     }
        
    //     Node* left= sortedLLtoBST(head,n/2);
        
    //     Node* root=head;
    //     root->left=left;
        
    //     head=head->right;
        
    //     Node *right= sortedLLtoBST(head,n- (n/2) -1);
    //     root->right=right;
    //     return root;
    // }
    // //Function to return a list of integers denoting the node 
    // //values of both the BST in a sorted order.
    // vector<int> merge(Node *root1, Node *root2)
    // {
    //   //Your code here
    // //   vector<int> ans;
    // //   if(!root1==NULL || !root2==NULL) return ans;
    
    
    // //step1 : convert BST into sorted DLL(in place)
    // Node* head1=NULL;
    // convertIntoSortedDLL(root1,head1);
    // head1->left=NULL;
    
    // Node* head2=NULL;
    // convertIntoSortedDLL(root2,head2);
    // head2->left=NULL;
    
    // //step 2: merge sorted linked list
    // Node* head=mergeLinkedList(head1,head2);
    
    // //step 3 : convert sortedLL to BST
    // return sortedLLtoBST(head,countNodes(head)); 
       
    // }
};


//{ Driver Code Starts.
int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       Node* root2 = buildTree(s);
    
       // getline(cin, s);
       Solution obj;
       vector<int> vec = obj.merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
}
// } Driver Code Ends