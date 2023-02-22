//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	void dfs(vector<vector<int>> &adj , int node , vector<int> &vis , stack<int> &stk){
	    vis[node]=1;
	    for(auto i: adj[node]){
	        if(!vis[i]){
	            dfs(adj , i , vis , stk);
	        }
	    }
	    stk.push(node);   //when the dfs traversal will be over
	}
	
	
	void dfs3(int node ,  vector<int> &vis ,vector<int> adjT[]){
	    vis[node]=1;
	    for(auto i: adjT[node]){
	        if(!vis[i]){
	            dfs3( i , vis , adjT);
	        }
	    }
	}
	
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)       
    {
        //code here
        //step 1 : sort the graph according to finishing time
        vector<int> vis(V , 0);
        stack<int> stk;
        for(int i=0;i<V;i++){
            if(!vis[i]) dfs(adj , i , vis , stk);
        }
        
        //step 2: reverse the graph
        vector<int> adjT[V];   //adjancy matrix to store reveresed graph
        
        for(int i=0;i<V;i++){
            vis[i]=0;  //reusing vis array for further use
            for(auto it: adj[i]){  //while traversing in adj array  , creating reverse graph adj array
                //earlier there was eddge from i -it , so reverse will be
                adjT[it].push_back(i);
            }
        }
        
        // step 3: computing the scc by traversing on graph using stack and new adj matrix
        int scc=0;
        
        while(!stk.empty()){
            int node =stk.top();
            stk.pop();
            if(!vis[node]){
                scc++;   //the number of times i call dfs is number of scc
                dfs3(node , vis , adjT);
            }
        }
        return scc;
        
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends