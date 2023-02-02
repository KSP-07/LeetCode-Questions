//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V , 0);  //for checking the already visted nodes
        vector<int> ans;  //for storing ans
        queue<int> q;  //for bfs we use queue
        q.push(0);   //since we have to always begin with 0 , pushing it in queue and marking 0th pos as visited
        vis[0]=1;
        while(!q.empty()){
            int data= q.front();
            q.pop();
            ans.push_back(data);
            for(auto i:adj[data]){
                if(!vis[i]){
                    vis[i]=1;   //ye hash is trh  vis mark kr rha
                    q.push(i);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends