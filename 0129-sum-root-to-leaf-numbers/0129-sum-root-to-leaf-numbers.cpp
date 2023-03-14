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
    void solve(TreeNode * root , string temp , long &sum){
        if(root==NULL){
            return;
        }
        temp+= to_string(root->val);
        if(root->left==NULL && root->right==NULL){
            // cout<<temp<<endl;
            sum += stoi(temp);            
        }
        
        solve(root->left , temp,sum);        
        solve(root->right , temp , sum);
    }
    int sumNumbers(TreeNode* root) {
        long sum = 0;
        solve(root, "",  sum);
        return sum;
    }
};