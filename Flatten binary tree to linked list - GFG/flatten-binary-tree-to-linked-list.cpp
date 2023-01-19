//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	Node *left, *right;
};

/* utility that allocates a new Node
   with the given key  */
Node* newNode(int key)
{
	Node* node = new Node;
	node->key = key;
	node->left = node->right = NULL;
	return (node);
}

Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

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
		if (i >= ip.size())
			break;
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

void inorder(struct Node* root)
{
	// base condition
	if (root == NULL)
		return;
	inorder(root->left);
	cout << root->key << " ";
	inorder(root->right);
}


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
//using intution of morris traversal...setting the left's most right to cur's right..for preorder..and cur(root's) right to cur's left..
//thus will thread the tree 
    void flatten(Node *root)
    {
        //code here
        Node *curr=root;
        while(curr){
            //finding predessor if left exist
            if(curr->left){
                Node *temp=curr->left;
                while(temp->right) temp=temp->right;
                
                temp->right=curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            //will move to right..if left is not there then simple right..otherwise also root's right will be set to 
            //root's left after threading
            curr=curr->right;
        }
    }
};


//another method
class Solution
{
    public:
    void preOrder(Node *root, Node *&prev){
        if(!root) return;
        
        preOrder(root->right,prev);
        preOrder(root->left,prev);
        root->left=NULL;
        root->right=prev;
        prev=root;
    }
    void flatten(Node *root)
    {
        //code here
        // Node *dummy=newNode(-1);
        Node *prev=NULL;
        preOrder(root, prev);
        
        // prev->left=NULL;
        // prev->right=NULL;
        
        // root = dummy->right;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
	cin >> t;
	getchar();

	while (t--)
	{

		string str;
		getline(cin, str);
	
		Node *root = buildTree(str);
		Solution ob;
		ob.flatten(root);
		inorder(root);


		cout << "\n";
	}

	return 0;
}

// } Driver Code Ends
