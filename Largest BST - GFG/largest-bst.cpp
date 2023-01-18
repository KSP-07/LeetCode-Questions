//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


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
    Node* root = newNode(stoi(ip[0]));

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
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class info{
    public:
    int maxi;
    int mini;
    bool isBst;
    int size;
};

class Solution{
    public:
//ek ek node pe ye dekh lenge ki uske left aur right bst hai ki ni , toh fir n*n time lagega
//pr aise hum left ka max aur right ka min maintain kr lenge aur ye bhi ki cur node bst bann rhi ki nhi , agr koi nhi hogi to ans update nhi hoga fir
//aise O(N) mai hojayga....

    info solve(Node *root , int &ans){
        if(!root) return {INT_MIN , INT_MAX , true,0};
        
        info left = solve(root->left  , ans);
        info right = solve(root->right , ans);
        
        info curNode;
        curNode.size = left.size + right.size +1;
        curNode.maxi= max(root->data , right.maxi);
        curNode.mini = min(root->data , left.mini);
        if(left.isBst && right.isBst  && (root->data > left.maxi && root->data< right.mini)){
            curNode.isBst=true;
        }
        else curNode.isBst = false;
        
        if(curNode.isBst) ans= max(ans , curNode.size); 
        
        return curNode;
    }
    
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	//Your code here
    	int maxSize=0;
    	info temp=solve(root,maxSize);
    	return maxSize;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}

// } Driver Code Ends