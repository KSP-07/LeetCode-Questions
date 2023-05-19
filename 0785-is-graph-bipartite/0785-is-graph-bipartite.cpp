/*
BFS

class Solution {
public:
    
    bool check(int start , vector<vector<int>> &adj , vector<int> &color){
         queue<int> q;
	    //pushing the starting vertex in queue alongwith marking color in color array
	    q.push(start);
	    color[start]=0;
	    while(!q.empty()){
	        int size = q.size();
	        while(size--){
	            int node = q.front();
	            q.pop();
	            
	            for(auto it : adj[node]){
	                if(color[it]==-1){   //if the adjacent node is not yet colored      
        	            color[it] = !color[node];   //storing opposite color of parent
	                    q.push(it);
	                }
	                //if the adjacent guy having the same color
	                //someone did color it on some other path
	                else if(color[it] == color[node]) return 0;
	            }
	        }
	    }
	    return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        
        for(int i = 0 ; i< n; i++){
            if(color[i] == -1 && !check(i , graph , color)){
                return false;
            }
        }
        return true;
    }
};
*/


class Solution {
public:
    bool dfs(int node,vector<vector<int>>& adj,vector<int>&color){
        if(color[node]==-1) color[node]=1;
        for(auto it :adj[node]){
            
            if(color[it]==-1){
                color[it]=1-color[node];
                if(dfs(it,adj,color)==false ) return false;
            }
            else if(color[node]==color[it]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int  n= graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(dfs(i,graph,color)==false) return false;
            }
        }
        return true;
        
    }
};

