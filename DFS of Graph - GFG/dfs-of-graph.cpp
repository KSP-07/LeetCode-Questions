//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    void dfs(auto &vis , auto &ans , auto &adj,auto node){
        //setting the curr node as visited
        vis[node]=1;
        //pushing curr node in ans as we have come to visit it ans will not visit it agian
        ans.push_back(node);
        
        //now traversing on the connecting edges of curr node
        for(auto i : adj[node]){
            //if curr node has any neighbour that is now already visied we take and call dfs on it
            if(!vis[i]){
                vis[i]=1;
                dfs(vis , ans , adj , i);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V,0);   //creating a visited array to keep track of visted nodes
        vector<int>ans;  //for storing ans
        // while()
        int start=0;   //we have to start from 0 , so setting start node as 0
        dfs(vis , ans , adj , start);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends