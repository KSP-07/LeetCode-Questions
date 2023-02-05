//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	//using dfs algo
	/*
	
	void dfs(int node , auto &stk , auto &vis , auto &adj){
	    vis[node]=1;
	    for(auto i:adj[node]){
	        if(!vis[i]){
	            dfs(i,  stk , vis , adj);
	        }
	    }
	    stk.push(node);     //here when recursion stack will start calling back then we will store it in stack so that we store vth in stack as 
	    //it will visit all the nodes then store recursively
	}
	
	
	//what we are doing is that , since topological sorting measn that in directed grapg G , the edge u->v , u should come first before v in the ans
	//so, we are doing dfs traversal from all the nodes of graph as in normal generally we did form 0 only , but there can we some vertex that can not be reached by others
	//since we want u in ans before v , we can use stack to store nodes while traversing to store v first , as when recursion stack will start calling back then
	//so we can get toplogical sorting ordre
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> ans , vis(V,0);
	    stack<int> stk;
	    
	    for(int i=0;i<V;i++){
	        if(vis[i]==0){
	            dfs(i , stk, vis , adj);
	        }
	    }
	    
	    while(!stk.empty()){
	        int temp=stk.top();
	        stk.pop();
	        ans.push_back(temp);
	    }
	    return ans;
	}
	
	*/
	
	
	//using bfs ( kahn's)...
	//counting indegree of nodes , the one will 0 indegree will come first in topological sort
	// so after taking in degree , we find 0th indegree nodes..push them in queue
	//then we use bfs algo..pop from queue , push it in ans , find it's adjacent , reduce their indegree..if it gets 0..push in queue
	
	vector<int> topoSort(int V, vector<int> adj[]) {
	    
	    queue<int> q;
	    
	    vector<int> indegree(V,0);
	    
	    //sari node leni hai isliye 0 se V tkk traverse kr rhe
	    for(int i=0 ;i<V;i++){
	        //ab har node pe uske neighbours lerhe
	        for(auto it:adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    //ab queue mai 0th indegree wale push kr rhe
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0) q.push(i);
	    }
	    
	    //now typical bfs
	    
	    vector<int> ans;
	    
	    while(!q.empty()){
	        int val = q.front();
	        q.pop();
	        ans.push_back(val);
	        for(auto i:adj[val]){
	            indegree[i]--;
	            if(indegree[i]==0) q.push(i);
	        }
	    }
	    
	    return ans;
	    
	}
	
	
	
	
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends