//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.  
    
    //using bfs and dfs...
    
    //using bfs , can be done by maintaining indegree or using topological sort
    // bool isCyclic(int V, vector<int> adj[]) {
    //     // code here
    //     vector<int> vis(V,0);
    //     queue<int> q;
    //     q.push(0);
    //     vis[0]=1;
        
    //     while(!q.empty()){
    //         int data = q.front();
    //         q.pop();
    //         for(auto x:adj[data]){
    //             if(vis[x]) return 1;
    //             else{
    //                 vis[x]=1;
    //                 q.push(x);
    //             }
    //         }
    //     }
    //     return 0;
    // }
    
    
    
    // using dfs by maintaining order vector , basically maintainig two visted array so as to overcome the call stack of recurion problem
    //what happened is once we filled all element in vis , call stack returns , and if a node had one more way to reach other node , it will be counted as 
    //already visted so it will prompt cycle , so what we can do is maintain a order..like setting element to 0 again in one of the vis array , so 
    //if there would be cycle , both vis array will have true values 
    
    
  bool solve(int src , auto &vis , auto &order, vector<int> adj[]){
      vis[src]=1;
      order[src]=1;
      
      for(auto i:adj[src]){
          if(!vis[i]){
              bool conf = solve(i , vis , order, adj);
              if(conf) return true;
          }
          else if(order[i]) return true;   //this means that the node we are visiting is 1 on both the visited array
      }
      order[src]=0;    //as the elements call stack will return back , we make node 0 in reverse , this ensure that node can visit already seen node more
      //and in case of cycle both vis and order will be 1
      return false;
  }
  
   bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V ,0);
        vector<int> order(V ,0);
        for(int i=0; i<V;i++){
            if(!vis[i]){
                bool c = solve(i , vis , order , adj);
                if(c) return true;   //this means a cycle was found
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends