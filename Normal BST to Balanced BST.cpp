void inorder(Node *root , auto &ans){
    if(!root) return;
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}

//mid element leke bst bana rahe to dono side se balanced bann jayga
Node *toBst(auto &ans , int s , int e){
    if(s>e) return NULL;
    int mid = s + (e-s)/2;
    
    Node *temp = new Node(ans[mid]);
    temp->left = toBst(ans , s , mid-1);
    temp->right =toBst(ans , mid+1,e);
    
    return temp;
}

Node* buildBalancedTree(Node* root)
{
	// Code here
	if(!root) return NULL;
	vector<int> ans;
	//sorted order store krlege array mai , then mid element se bst bnane lagage to balanced aayga
	inorder(root , ans);
	int n=ans.size();
	
	Node *temp=toBst(ans, 0 , n-1);
	
	return temp;
}
