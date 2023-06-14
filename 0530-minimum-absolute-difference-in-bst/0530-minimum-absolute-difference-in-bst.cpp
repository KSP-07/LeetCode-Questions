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
    
    void inorder(TreeNode *root , vector<int> &arr){
        if(!root) return;
        
        inorder(root->left , arr);
        arr.push_back(root->val);
        inorder(root->right , arr);
    }
    int getMinimumDifference(TreeNode* root) {
        if(!root) return 0;
        
        vector<int> container;
        
        inorder(root , container);
        
        int ans = 1e9;
        int n = container.size();
        for(int i = 0; i < n -1 ; i++ ){
            if(abs(container[i] - container[i+1]) < ans) ans = abs(container[i] - container[i+1]);
        }
        return ans==1e9? container[0] : ans;
    }
};