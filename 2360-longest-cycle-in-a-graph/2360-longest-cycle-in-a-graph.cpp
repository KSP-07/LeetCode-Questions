class Solution {
public:
     void dfs(int node, vector<int>& edges, unordered_map<int, int>& dist, vector<bool>& visit , int &ans){
         visit[node] = true;
         int neighbour = edges[node];
         
         if(neighbour!= -1 && !visit[neighbour]){
             dist[neighbour] = dist[node] +1;
             dfs(neighbour , edges , dist , visit ,ans);
         }
         else if(neighbour != -1 && dist.count(neighbour)){
             ans = max(ans , dist[node] - dist[neighbour] +1);
         }
     }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> visit(n);
        int ans = -1;
        for(int i =0 ; i<n ;i++){
            if(!visit[i]){
                unordered_map<int,int> mp;
                mp[i]=1;
                dfs(i , edges , mp , visit , ans);
            }
        }
        return ans;
    }
};