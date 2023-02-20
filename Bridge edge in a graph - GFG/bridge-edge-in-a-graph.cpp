//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    void dfs(int i,vector<int> &vis,vector<int> adj[])
    {  vis[i] = 1;
       for(auto c : adj[i])
       {
           if(!vis[c])
           {
              
               dfs(c,vis,adj);
           }
       }
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
         adj[c].erase(find(adj[c].begin() , adj[c].end() , d));
         adj[d].erase(find(adj[d].begin() , adj[d].end() , c));
         vector<int> vis(V,0);
         int cnt = 0;
         dfs(c,vis,adj);
        return !vis[d];
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}


// } Driver Code Ends