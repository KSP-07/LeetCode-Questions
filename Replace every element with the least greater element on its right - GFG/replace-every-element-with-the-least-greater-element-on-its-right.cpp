//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++
class Node{
    public:
    int data;
    Node *left,*right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};

//here we are creating a bst 
Node *insert(Node *root,int val,Node* &suc){
    if(!root){   //agr first node hue , to sirf ek root node banegi aur root pe pointer return hojayga , hume basically succ chiye element ka..element insert krte tym
       return root=new Node(val);
    }
    else if(val >=root->data){  //agar val badi hue, to uska successor right side mai milega aur val bhi insert right mai hii hogi
        root->right=insert(root->right,val , suc);   //root ke right mai naye element ka pointer kr rhee
    }
    else{
        suc=root;    //agar element chota hai toh phir ye hoskta ki current node naye element ka successor bann sake
        root->left= insert(root->left, val,suc);   //root ke left mai naye element ka pointer kr rahe
    }
    return root;
}

class Solution{
    public:
    //right side se elements nikalne to right side se bst form krenge aur harr ek insertion pe least 
    //greater element nikal lenge , kuki agar nhi kara check toh phir gadbad hojaygi..for ex curr node 
    // hai 3..next mai aaya 5..fir aaya 4..to phir 3 ka succ 4 hojayga...jbki hume right side pe nikalne thee
    //aur 4..3 ke left mai thaa
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        Node* root=NULL;   //first node null krdi suru mai
        for(int i=n-1;i>=0;i--){
            Node* suc=NULL;  //suc ko null set krdia..agar koi succ mila toh vo aayga nhi toh -1 krdenge
            root=insert(root,arr[i],suc);
            if(suc){
                arr[i]=suc->data;
            }
            else arr[i]=-1;
        }
        return arr;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findLeastGreater(arr, n);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout <<endl;
	}
	return 0;
}

// } Driver Code Ends