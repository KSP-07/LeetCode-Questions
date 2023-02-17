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
    
//     void diff(TreeNode* root , vector<int> &ans){
//         if(!root) return ;
        
//         diff(root->left , ans);
//         ans.push_back(root->val);
//         diff(root->right , ans);
//     }
    
    
//     int minDiffInBST(TreeNode* root) {
//         int mini =INT_MAX;
//         vector<int> ans;
//         diff(root , ans);
        
//         for(int i=0;i<ans.size() - 1;i++){
//             mini = min(mini , ans[i+1] - ans[i]);
//         }
//         return mini;
//     }
    
    
    //just by taking a previous pointer
    
    void diff(TreeNode* root , int &mini , int &prev){
        
        if(!root) return ;
        
        //traversing towards left
        diff(root->left , mini, prev);
        
        //checking diff with prev pointer and then moving prev to current root
        if(prev!=-1){
            mini = min(mini , (root->val - prev));
        }
        prev = root->val;
        
        //traversing towards right
        diff(root->right , mini , prev);
        
        
    }
    int minDiffInBST(TreeNode* root){
        int mini = INT_MAX;
        int prev =-1;
        
        diff(root ,  mini , prev);
        
        return mini;
    }
    
};