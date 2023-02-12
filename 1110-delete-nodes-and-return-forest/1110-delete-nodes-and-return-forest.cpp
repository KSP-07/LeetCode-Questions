// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */

class Solution {
public:
    vector<TreeNode*>res;
    unordered_set<int>st;
    void deleteNodeUtil(TreeNode* &root){
        if(root){
            deleteNodeUtil(root->left);
            deleteNodeUtil(root->right);
            if(st.find(root->val)!=st.end()){
                if(root->left)res.push_back(root->left);
                if(root->right)res.push_back(root->right);
                root=NULL;
                delete root;
            }
        }
        

    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
//         //del krne wale elements set mai daal diye , ab dekhenhe ki set mai val hai ki nhi 
//         //hogi toh usse del krdenge nhi toh ans mai add
        for(int i=0;i<to_delete.size();i++){
            st.insert(to_delete[i]);
        }
        deleteNodeUtil(root);
        if(root)res.push_back(root);
        return res;
    }
};