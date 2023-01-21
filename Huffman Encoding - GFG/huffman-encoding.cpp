//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends




class Node{
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int d){
        data = d;
        left = NULL;
        right= NULL;
    }
};

class cmp{
    public:
    bool operator()(Node*a , Node* b){
        return a->data > b->data;
    }
};

class Solution
{
	public:
	
	void traverse(auto *root , auto &ans , auto temp){
	    //base case...agar root se leaf pahuch jayge to uss node tkk ka code milgyaa
	    if(root->left==NULL and root->right==NULL){
	        ans.push_back(temp);
	        return;
	    } 
	    traverse(root->left , ans , temp+'0');  //left side jaate mai 0 lagate code mai
	    traverse(root->right ,ans , temp+'1');   //right side jaate mai 1 lagate
	}
	
	
		vector<string> huffmanCodes(string S,vector<int> f,int n)
		{
		    // Code here
		    priority_queue<Node* , vector<Node*> , cmp> pq;
		    
		    for(int i=0;i<n;i++){
		        Node *temp = new Node(f[i]);   //creating new nodes for each char's frequency
		        pq.push(temp);    //inserting the node in priority queue
		    }
		    
		    while(pq.size()>1){
		        Node *left = pq.top();   //sbse smallest wala left side banega
		        pq.pop();
		        Node *right = pq.top();   //second smalles ab right side banega and dono ke sum se root node
		        pq.pop();
		        
		        Node *temp = new Node(left->data + right->data);  //root node mana rahe optimal merge pattern se
		        
		        //ab root ke left and right set kr rhee
		        temp->left=left;    
		        temp->right = right;
		        
		        //now pushing new created node in pq for further evaluation
		        pq.push(temp);
		    }
		    
		    Node *root=pq.top();   //final sbse bada element final root banega
		    //ab ek ans vec mai codes store krra rhee
		    vector<string> ans;
		    string temp="";
		    traverse(root , ans , temp);
		    
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends