/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
//     void inorder(vector<int> &arr  , TreeNode*root){
//         if(!root) {
//             arr.push_back(-1);
//             return;
//         }
        
//         inorder(arr , root->left);
//         arr.push_back(root->val);
//         inorder(arr , root->right);
//     }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false;
        
        if(p->val != q->val) return false;
        
        return isSameTree(p->left , q->left) && isSameTree(p->right , q->right);
    }
};