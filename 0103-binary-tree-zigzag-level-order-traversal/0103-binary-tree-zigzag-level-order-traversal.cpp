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
    
    void solve(TreeNode* root , vector<vector<int>> &ans , int cnt){
        if(root==NULL) return;
        
        queue<TreeNode*> q;
        q.push(root);
        // cnt++;
        // ans.push_back({root->val});
        // int ch=0;
        
        while(!q.empty()){
            int size = q.size();
            // q.pop();
            vector<int> temp;
            
            while(size--){
                auto node = q.front();
                q.pop();
                
                if(cnt%2==0){
                    temp.push_back(node->val);
                }
                else{
                    temp.insert(temp.begin() , node->val);
                }
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                
            }
            cnt++;
            ans.push_back(temp);
        }
        
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        
        vector<vector<int>> ans;
        solve(root , ans , 0);
        return ans;
    }
};