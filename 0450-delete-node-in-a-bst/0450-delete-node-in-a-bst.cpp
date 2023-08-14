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
    
    TreeNode *findMin (TreeNode *root){
        if(!root) return NULL;
        
        while(root->left) root = root->left;
        
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        
        if(root->val == key){ 
            
            /*4 cases
            1. is leaf node
            2. no right
            3. no left
            4. has both right and left */
            
            if(!root->left && !root->right ){
                delete root;
                return NULL;
            }
            
            else if( !root->left && root->right){
                TreeNode *temp = root->right ;
                delete root;
                return temp ;
            }
            
            else if(root->left && !root->right){
                TreeNode *temp = root->left ;
                delete root ;
                return temp ;
            }
            
            else if(root->left && root->right){
                int minVal = findMin (root->right) -> val;
                root->val = minVal ;
                
                root->right = deleteNode (root->right , minVal);
                
                return root;
            }
          
        
        }
        else if(root->val > key){
            root->left = deleteNode(root->left ,key);
        }
        else root->right = deleteNode(root->right , key);
        
        return root;
    }
};