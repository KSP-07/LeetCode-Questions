//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

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
/*Complete the function below

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

class Solution {
  public:
  //update fun
  bool up(Node* root , int i,int k,int &ans){
      if(i==k){
          ans=root->data;
          return true;
      }
      return false;
  }
  
  
  
  //morris inorder traversal
  
  void solve(Node* root, int i , int k,int &ans, int &flag){
      if(up(root,i,k,ans)){ flag=1; return;}
      else{
          if(root==NULL) return;
          else{
              Node* cur=root;
              while(cur!=NULL){
                  if(cur->left==NULL){
                      if(up(cur, ++i , k,ans)){ flag=1; break;}   //checking if i==k
                      else cur=cur->right;
                  }
                  else{
                      //finding predecessor
                      Node *pre=cur->left;
                      while(pre->right!=NULL && pre->right!=cur) pre=pre->right;
                      
                      //now checking if thread is already there or not
                      if(pre->right==NULL){  //thread not there
                          pre->right=cur;   //making thread to the curr node i.e from just smaller element of root node to root
                          cur=cur->left;   //now traversing for the left subtree;
                      }
                      else{    //thread is already present
                        if(up(cur ,++i,k,ans)){ flag=1; break;}   //checking if now curr element i.e root is req element
                        pre->right=NULL;         //breaking the thread since we 
                        cur=cur->right;     //now traversing for the right subtree
                          
                      }
                  }
              }
          }
      }
  }
  
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int k) {
        // add code here.
        int ans=0;
        int flag=0;
        solve(root, 0,k ,ans,flag);
        if(flag) return ans;
        return -1;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);

        getline(cin, s);
        int k = stoi(s);
        //  getline(cin, s);
        Solution obj;
        cout << obj.KthSmallestElement(root, k) << endl;
        // cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends