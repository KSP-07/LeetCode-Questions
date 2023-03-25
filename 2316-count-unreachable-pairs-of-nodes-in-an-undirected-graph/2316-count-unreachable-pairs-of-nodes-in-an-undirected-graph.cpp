class Solution {
public:
    int dfs(vector<vector<int>>&adj , int node,vector<int>&vis){
        int cnt =1;
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it]){
                cnt+= dfs(adj , it , vis);
            }
        }
        return cnt;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(n);
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        long long numOfPairs = 0 , sizeOfComponet =0 , remaining_nodes=n;
        vector<int>vis(n , 0);
        for(int i=0; i<n;i++){
            if(!vis[i]){
                sizeOfComponet =dfs(adj , i , vis);
                numOfPairs += sizeOfComponet *(remaining_nodes -sizeOfComponet);
                remaining_nodes -= sizeOfComponet;
            }
        }
        return numOfPairs;
    }
};