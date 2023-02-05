//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.  
    
    //using bfs and dfs...
    
    /*
    In Kahn's algorithm, a node only enters the queue if its indegree becomes zero 
    and then it further decrements the indegree values of its adjacent nodes right. 
    But in the case of cyclic graph , there will be a node from where the cycle will be starting and then coming to an end. 
    So in order for the elements present in the cycle to get pushed into the queue, 
    that cycle starting node's indegree must become zero right. 
    But but but, that node's indegree will never become zero 
    as one of the node from the cycle (the second last element) will be pointing towards the starting node.
    Just imagine with a diagram in the video. So if that node's indegree will never become zero , 
    then it will restrict its adjacent nodes(at least) to get evaluated and 
    hence the total number of nodes getting pushed into the queue (cnt) will never become (=N).
    */
    
    //using bfs , can be done by maintaining using topological sort and placing a counter on every pop from queue
    //since , loop will not run for more than N times , if counter reaches the same than there is a cycle
    
    bool isCyclic(int V, vector<int> adj[]){
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
	    
	    int cnt=0;
	    
	    while(!q.empty()){
	        int val = q.front();
	        q.pop();
	        cnt++;
	        for(auto i:adj[val]){
	            indegree[i]--;
	            if(indegree[i]==0) q.push(i);    //jis node pe cycle hogi wo push hii nhi hogi queue mai
	        }
	    }
        if(cnt!=V) return true;     //cnt of ans of topo sort is not equal to the number of nodes
        return false;
    }
    
    
    
    
    
    
    // using dfs by maintaining order vector , basically maintainig two visted array so as to overcome the call stack of recurion problem
    //what happened is once we filled all element in vis , call stack returns , and if a node had one more way to reach other node , it will be counted as 
    //already visted so it will prompt cycle , so what we can do is maintain a order..like setting element to 0 again in one of the vis array , so 
    //if there would be cycle , both vis array will have true values 
    
  /*  
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
    */
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