class Solution {
public:
    
    void dfs(int node ,vector<vector<pair<int,int>>> &adj ,vector<int>&vis , int &ans){
        vis[node]=1;
        for(auto edge:adj[node]){
            ans = min(ans , edge.second);
            if(!vis[edge.first]){
                dfs(edge.first , adj , vis , ans);
            }
        }
    }
    
    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto road: roads){
            adj[road[0]].push_back({road[1] , road[2]});
            adj[road[1]].push_back({road[0] , road[2]});
        }
        int ans = numeric_limits<int>:: max();
        vector<int> vis(n+1);
        dfs(1 , adj , vis , ans);
        return ans;
    }
};